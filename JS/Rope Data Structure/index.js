class Node {
  constructor(parent, kind) {
    (this.parent = parent), (this.kind = kind);
  }
}

class Leaf extends Node {
  constructor(parent, val) {
    super(parent, "leaf");
    this.val = val;
  }
}

class Branch extends Node {
  constructor(parent, weight, left, right) {
    super(parent, "branch");
    this.weight = weight;
    this.left = left;
    this.right = right;
  }
}

class Rope {
  constructor() {
    this.head = null;
  }
  static fromString(str) {
    const rope = new Rope();
    const leaf = new Leaf(null, str);
    rope.head = leaf;
    return rope;
  }

  traverse(node = this.head) {
    if (node.kind == "leaf") {
      return node.val;
    }

    let leftBranch = leftBranch + this.traverse(node.left);
    let rightBranch = rightBranch + this.traverse(node.right);
    return leftBranch + rightBranch;
  }
  concat
}

const rope1 = Rope.fromString("Hello");
const rope2 = Rope.fromString("World");

console.log(rope1.traverse());
