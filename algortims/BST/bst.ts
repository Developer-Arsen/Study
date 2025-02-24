interface INode {
  val: number;
  left: INode | null;
  right: INode | null;
}

class TreeNode implements INode {
  val: number;
  left: INode | null;
  right: INode | null;

  constructor(val: number) {
    this.val = val;
    this.left = null;
    this.right = null;
  }
}

class BST {
  root: TreeNode | null;
  size: number;

  constructor() {
    this.root = null;
    this.size = 0;
  }

  private insertHelper(node: TreeNode | null, val: number): TreeNode {
    if (!node) {
      this.size++;
      return new TreeNode(val);
    }

    if (node.val < val) {
      node.right = this.insertHelper(node.right, val);
    } else {
      node.left = this.insertHelper(node.left, val);
    }
    return node;
  }

  public insert(val: number): TreeNode {
    if (!this.root) {
      this.root = new TreeNode(val);
      return this.root;
    }

    return this.insertHelper(this.root, val);
  }

  public inOrderTraversal(
    node: TreeNode | null,
    result: number[] = []
  ): number[] {
    if (node) {
      this.inOrderTraversal(node.left, result);
      result.push(node.val);
      this.inOrderTraversal(node.right, result);
    }
    return result;
  }
  public search(
    val: number,
    node: TreeNode | null = this.root
  ): TreeNode | null {
    if (!node) {
      return null;
    }
    if (node.val == val) return node;
    if (node.val < val) {
      return this.search(val, node.right);
    }
    return this.search(val, node.left);
  }
  public getHeight(node: TreeNode | null = this.root): number {
    if (!node) {
      return -1;
    }
    let left = this.getHeight(node.left);
    let right = this.getHeight(node.right);
    return Math.max(left, right) + 1;
  }
  public getMin(node: TreeNode | null = this.root): TreeNode | null {
    let tmp: TreeNode | null = node;
    while (tmp?.left) {
      tmp = tmp?.left;
    }
    return tmp;
  }
  public getMax(node: TreeNode | null = this.root): TreeNode | null {
    let tmp: TreeNode | null = node;
    while (tmp?.right) {
      tmp = tmp?.right;
    }
    return tmp;
  }

  private eraseHelper(target: number, node: TreeNode | null = this.root) {
    if (!target) return null;
    if (!node) return null;

    if (node.val < target) {
      node.right = this.eraseHelper(target, node.right);
    } else {
      node.left = this.eraseHelper(target, node.left);
    }

    if (node.val == target) {
      if (!node.left && !node.right) return null;
      if (!node.left) return node.right;
      if (!node.right) return node.left;

      let successor = this.getSuccessor(node);
      if (successor) {
        node.val = successor.val;
      }
      node.right = this.eraseHelper(node.val, node.right);
    }
    return node;
  }

  public erase(target: number) {
    this.root = this.eraseHelper(target, this.root);
  }

  public getSuccessor(node: TreeNode | null) {
    if (!node) return null;

    if (node.right) {
      let successor = node.right;
      while (successor.left) {
        successor = successor.left;
      }
      return successor;
    }

    let current: TreeNode | null = this.root;
    let successor: TreeNode | null = null;

    while (current && current.val != node.val) {
      if (node.val < current.val) {
        successor = current;
        current = current.left;
      } else if (node.val > current.val) {
        current = current.right;
      }
    }

    return successor;
  }

  public getPredessor(node: TreeNode | null) {
    if (!node) return null;
    if (node.left) {
      let predeccessor = node.left;
      while (predeccessor.right) {
        predeccessor = predeccessor.right;
      }
      return predeccessor;
    }

    let current: TreeNode | null = this.root;
    let predeccessor: TreeNode | null = null;

    while (current && current.val != node.val) {
      if (node.val < current.val) {
        current = current.left;
      } else {
        predeccessor = current;
        current = current.right;
      }
    }
    return predeccessor;
  }

  public preOrderWhile(node: TreeNode | null) {
    if (!node) return [];

    let stack: TreeNode[] = [node];
    let arr: number[] = [];
    let current: TreeNode | null = node;

    while (stack.length) {
      while (current) {
        arr.push(current.val);
        stack.push(current);
        current = current.left;
      }

      let tmp = stack.pop();
      if (tmp) {
        current = tmp.right;
      }
    }

    return arr;
  }
}

const bst = new BST();
bst.insert(10);
bst.insert(5);
bst.insert(15);
bst.insert(3);
bst.insert(7);
bst.insert(13);
bst.insert(11);
bst.insert(17);
bst.insert(120);

// console.log();
// console.log(bst.getPredessor(bst.search(10)));
// console.log(bst.erase(15));

// bst.erase(120);

// console.log(bst.search(14));
// console.log(bst.search(13));
// console.log(bst.getHeight());
// console.log(bst.getMin());
// console.log(bst.getMin(bst.search(13)));
// console.log(bst.getMax());

console.log(bst.inOrderTraversal(bst.root));
console.log(bst.preOrderWhile(bst.root));
