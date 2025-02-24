interface INode {
  val: number;
  left: INode | null;
  right: INode | null;
  height: number;
}

class TreeNode implements INode {
  val: number;
  left: INode | null;
  right: INode | null;
  height: number;

  constructor(val: number, height: number = 0) {
    this.val = val;
    this.left = null;
    this.right = null;
    this.height = height;
  }
}

class AVL {
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
    node.height = this.getHeight(node);

    const leftHeight = this.getHeight(node.left);
    const rightHeight = this.getHeight(node.right);

    const bf = leftHeight - rightHeight;
    if (bf > 1 && leftHeight > 0) {
      return this.rotateRight(node);
    }
    if (bf > 1 && node.left && leftHeight < 0) {
      node.left = this.rotateLeft(node.left);
      return this.rotateRight(node);
    }
    if (bf < -1 && rightHeight < 0) {
      return this.rotateLeft(node);
    }
    if (bf < -1 && node.right && rightHeight > 0) {
      node.right = this.rotateRight(node.right);
      return this.rotateLeft(node);
    }
    return node;
  }

  public balance(node: TreeNode, val: number): TreeNode {
    const leftHeight = this.getHeight(node.left);
    const rightHeight = this.getHeight(node.right);
    const bf = leftHeight - rightHeight;

    // Left-Left (LL) Case → Rotate Right
    if (bf > 1 && node.left && val < node.left.val) {
      return this.rotateRight(node);
    }

    // Left-Right (LR) Case → Rotate Left on Left Child, then Rotate Right
    if (bf > 1 && node.left && val > node.left.val) {
      node.left = this.rotateLeft(node.left);
      return this.rotateRight(node);
    }

    // Right-Right (RR) Case → Rotate Left
    if (bf < -1 && node.right && val > node.right.val) {
      return this.rotateLeft(node);
    }

    // Right-Left (RL) Case → Rotate Right on Right Child, then Rotate Left
    if (bf < -1 && node.right && val < node.right.val) {
      node.right = this.rotateRight(node.right);
      return this.rotateLeft(node);
    }

    return node; // No rotation needed
  }

  private rotateLeft(node: TreeNode): TreeNode {
    const root = node.right;
    if (!root) return node;
    const T1 = root?.left;

    root.left = node;
    node.right = T1;

    return root;
  }

  private rotateRight(node: TreeNode): TreeNode {
    const root = node.left;
    if (!root) return node;
    const T1 = root?.right;

    root.right = node;
    node.left = T1;

    return root;
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
    if (node === null) return 0;
    const left = this.getHeight(node.left);
    const right = this.getHeight(node.right);
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

const avl = new AVL();
avl.insert(10);
avl.insert(5);
avl.insert(15);
avl.insert(3);
avl.insert(7);
avl.insert(13);
avl.insert(11);
avl.insert(17);
avl.insert(120);

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

console.log(avl.preOrderWhile(avl.root));
