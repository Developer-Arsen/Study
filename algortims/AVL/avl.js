var TreeNode = /** @class */ (function () {
    function TreeNode(val, height) {
        if (height === void 0) { height = 0; }
        this.val = val;
        this.left = null;
        this.right = null;
        this.height = height;
    }
    return TreeNode;
}());
var AVL = /** @class */ (function () {
    function AVL() {
        this.root = null;
        this.size = 0;
    }
    AVL.prototype.insertHelper = function (node, val) {
        if (!node) {
            this.size++;
            return new TreeNode(val);
        }
        if (node.val < val) {
            node.right = this.insertHelper(node.right, val);
        }
        else {
            node.left = this.insertHelper(node.left, val);
        }
        node.height = this.getHeight(node);
        return this.balance(node, val);
        var leftHeight = this.getHeight(node.left);
        var rightHeight = this.getHeight(node.right);
        var bf = leftHeight - rightHeight;
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
    };
    AVL.prototype.balance = function (node, val) {
        var leftHeight = this.getHeight(node.left);
        var rightHeight = this.getHeight(node.right);
        var bf = leftHeight - rightHeight;
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
    };
    AVL.prototype.rotateLeft = function (node) {
        var root = node.right;
        var T1 = root === null || root === void 0 ? void 0 : root.left;
        root.left = node;
        node.right = T1;
        return root;
    };
    AVL.prototype.rotateRight = function (node) {
        var root = node.left;
        var T1 = root === null || root === void 0 ? void 0 : root.right;
        root.right = node;
        node.left = T1;
        return root;
    };
    AVL.prototype.insert = function (val) {
        if (!this.root) {
            this.root = new TreeNode(val);
            return this.root;
        }
        return this.insertHelper(this.root, val);
    };
    AVL.prototype.inOrderTraversal = function (node, result) {
        if (result === void 0) { result = []; }
        if (node) {
            this.inOrderTraversal(node.left, result);
            result.push(node.val);
            this.inOrderTraversal(node.right, result);
        }
        return result;
    };
    AVL.prototype.search = function (val, node) {
        if (node === void 0) { node = this.root; }
        if (!node) {
            return null;
        }
        if (node.val == val)
            return node;
        if (node.val < val) {
            return this.search(val, node.right);
        }
        return this.search(val, node.left);
    };
    AVL.prototype.getHeight = function (node) {
        if (node === void 0) { node = this.root; }
        if (node === null)
            return 0;
        var left = this.getHeight(node.left);
        var right = this.getHeight(node.right);
        return Math.max(left, right) + 1;
    };
    AVL.prototype.getMin = function (node) {
        if (node === void 0) { node = this.root; }
        var tmp = node;
        while (tmp === null || tmp === void 0 ? void 0 : tmp.left) {
            tmp = tmp === null || tmp === void 0 ? void 0 : tmp.left;
        }
        return tmp;
    };
    AVL.prototype.getMax = function (node) {
        if (node === void 0) { node = this.root; }
        var tmp = node;
        while (tmp === null || tmp === void 0 ? void 0 : tmp.right) {
            tmp = tmp === null || tmp === void 0 ? void 0 : tmp.right;
        }
        return tmp;
    };
    AVL.prototype.eraseHelper = function (target, node) {
        if (node === void 0) { node = this.root; }
        if (!target)
            return null;
        if (!node)
            return null;
        if (node.val < target) {
            node.right = this.eraseHelper(target, node.right);
        }
        else {
            node.left = this.eraseHelper(target, node.left);
        }
        if (node.val == target) {
            if (!node.left && !node.right)
                return null;
            if (!node.left)
                return node.right;
            if (!node.right)
                return node.left;
            var successor = this.getSuccessor(node);
            if (successor) {
                node.val = successor.val;
            }
            node.right = this.eraseHelper(node.val, node.right);
        }
        return node;
    };
    AVL.prototype.erase = function (target) {
        this.root = this.eraseHelper(target, this.root);
    };
    AVL.prototype.getSuccessor = function (node) {
        if (!node)
            return null;
        if (node.right) {
            var successor_1 = node.right;
            while (successor_1.left) {
                successor_1 = successor_1.left;
            }
            return successor_1;
        }
        var current = this.root;
        var successor = null;
        while (current && current.val != node.val) {
            if (node.val < current.val) {
                successor = current;
                current = current.left;
            }
            else if (node.val > current.val) {
                current = current.right;
            }
        }
        return successor;
    };
    AVL.prototype.getPredessor = function (node) {
        if (!node)
            return null;
        if (node.left) {
            var predeccessor_1 = node.left;
            while (predeccessor_1.right) {
                predeccessor_1 = predeccessor_1.right;
            }
            return predeccessor_1;
        }
        var current = this.root;
        var predeccessor = null;
        while (current && current.val != node.val) {
            if (node.val < current.val) {
                current = current.left;
            }
            else {
                predeccessor = current;
                current = current.right;
            }
        }
        return predeccessor;
    };
    AVL.prototype.preOrderWhile = function (node) {
        if (!node)
            return [];
        var stack = [node];
        var arr = [];
        var current = node;
        while (stack.length) {
            while (current) {
                arr.push(current.val);
                stack.push(current);
                current = current.left;
            }
            var tmp = stack.pop();
            if (tmp) {
                current = tmp.right;
            }
        }
        return arr;
    };
    return AVL;
}());
var avl = new AVL();
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
