// class TreeNode {
//   constructor(val) {
//     this.val = val;
//     this.parent = null;
//     this.left = null;
//     this.right = null;
//     this.color = null;
//   }
// }

// class RBT {
//   constructor() {
//     this.nil = new TreeNode(-Infinity);
//     this.root = this.nil;
// this.colors = {
//   RED: "RED",
//   BLACK: "BLACK",
// };
//   }

//   leftRotate(z) {

//   }

//   insert(z) {
//     let tmp = this.root;
//     let parent = this.nil;
//     while (tmp != this.nil) {
//       if (z.val < tmp.val) {
//         tmp = tmp.left;
//       } else tmp = tmp.right;
//     }
//     z.parent = parent;
//     if (y == this.nil) {
//       this.root = z;
//     } else if (z.val < y.val) {
//       y.left = z;
//     } else y.right = z;
//     z.color = this.colors.RED;
//     z.left = z.left = this.nil;
//     this.insertFixup(z);
//   }

//   insertFixup(z) {
//     while (z.parent.color == this.colors.RED) {
//         if (z.parent.parent.left = z.parent) {
//             y = z.parent.parent.right;
//             if (y.color == this.colors.RED) {
//                 z.parent.color = this.colors.BLACK;
//                 y.color = this.colors.BLACK;
//                 z.parent.parent = this.colors.RED;
//                 z = z.parent.parent;
//             }
//             else {
//                 if (z == z.parent.right) {
//                     z = z.parent;
//                     this.leftRotate(z);
//                 }

//             }
//         }
//     }
//   }
// }

// 1. each node should have either red or black color
// 2. the root is black
// 3. Each leaf is black
// 4. If node is red then both two of it's child's are black
// 5. Each node, all simple paths (path from node to discandant leaf) should have the same amount number of black nodes

class TreeNode {
  constructor(val) {
    this.key = val;
    this.parent = null;
    this.left = null;
    this.right = null;
    this.color = null;
  }
}

class RBT {
  constructor() {
    this.colors = {
      RED: "RED",
      BLACK: "BLACK",
    };
    this.root = null;
    this.nil = new TreeNode(Infinity);
    this.nil.color = this.colors.BLACK;
  }

  leftRotate(x) {
    y = x.right;
    x.right = y.left;
    if (y.left != this.nil) y.left.parent = x;
    y.parent = x.parent;
    if (x.parent == this.nil) this.root = y;
    else if (x == x.parent.left) x.parent.left = y;
    else x.parent.right = y;
    y.left = x;
    x.parent = y;
  }

  rightRotate(x) {
    y = x.left;
    x.left = y.right;
    if (y.right != this.nil) y.right.parent = x;
    y.parent = x.parent;

    if (x.parent == this.nil) this.root = y;
    else if (x == x.parent.left) x.parent.left = y;
    else x.parent.right = y;

    y.right = x;
    x.parent = y;
  }

  insertFixup(z) {
    while (z.parent.color === this.colors.RED) {
      if (z.p == z.parent.parent.left) {
        let y = z.parent.parent.right;
        if (y.color === this.colors.RED) {
          y.color = this.colors.BLACK;
          z.parent.color = this.colors.BLACK;
          z.parent.parent = this.colors.RED;
          z = z.parent.parent;
        } else {
          if (z == z.parent.right) {
            z = z.parent;
            this.leftRotate(z);
          }
          z.parent.color = this.colors.BLACK;
          z.parent.parent = this.colors.RED;
          this.rightRotate(z.parent.parent);
        }
      } else {
        let y = z.parent.parent.left;
        if (y.color == this.colors.RED) {
          y.color = this.colors.BLACK;
          x.parent.color = this.colors.BLACK;
          x.parent.parent.color = this.colors.RED;
          z = z.parent.parent;
        } else {
          if (z == z.parent.left) {
            z = z.parent;
            this.rightRotate(z);
          }
          z.parent = this.colors.BLACK;
          z.parent.parent = this.colors.RED;
          this.leftRotate(z.parent.parent);
        }
      }
    }
    this.root.color = this.colors.BLACK;
  }

  insert(z) {
    let parent = this.nil;
    let tmp = this.root;
    while (tmp != this.nil) {
      parent = tmp;
      if (z.key < tmp.ley) tmp = tmp.left;
      else tmp = tmp.right;
    }
    z.parent = tmp;
    if (parent === this.nil) {
      this.root = z;
    } else if (z.key < tmp.key) {
      tmp.left = z;
    } else tmp.right = z;
    z.left = this.nil;
    z.right = this.nil;
    z.color = this.colors.RED;
    this.insertFixup(z);
  }
}
