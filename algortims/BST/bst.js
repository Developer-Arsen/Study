var TreeNode = /** @class */ (function () {
    function TreeNode(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
    return TreeNode;
}());
var BST = /** @class */ (function () {
    function BST() {
        this.root = null;
        this.size = 0;
    }
    BST.prototype.insertHelper = function (node, val) {
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
        return node;
    };
    BST.prototype.insert = function (val) {
        if (!this.root) {
            this.root = new TreeNode(val);
            return this.root;
        }
        return this.insertHelper(this.root, val);
    };
    BST.prototype.inOrderTraversal = function (node, result) {
        if (result === void 0) { result = []; }
        if (node) {
            this.inOrderTraversal(node.left, result);
            result.push(node.val);
            this.inOrderTraversal(node.right, result);
        }
        return result;
    };
    BST.prototype.search = function (val, node) {
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
    BST.prototype.getHeight = function (node) {
        if (node === void 0) { node = this.root; }
        if (!node) {
            return -1;
        }
        var left = this.getHeight(node.left);
        var right = this.getHeight(node.right);
        return Math.max(left, right) + 1;
    };
    BST.prototype.getMin = function (node) {
        if (node === void 0) { node = this.root; }
        var tmp = node;
        while (tmp === null || tmp === void 0 ? void 0 : tmp.left) {
            tmp = tmp === null || tmp === void 0 ? void 0 : tmp.left;
        }
        return tmp;
    };
    BST.prototype.getMax = function (node) {
        if (node === void 0) { node = this.root; }
        var tmp = node;
        while (tmp === null || tmp === void 0 ? void 0 : tmp.right) {
            tmp = tmp === null || tmp === void 0 ? void 0 : tmp.right;
        }
        return tmp;
    };
    BST.prototype.eraseHelper = function (target, node) {
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
    BST.prototype.erase = function (target) {
        this.root = this.eraseHelper(target, this.root);
    };
    BST.prototype.getSuccessor = function (node) {
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
    BST.prototype.getPredessor = function (node) {
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
    BST.prototype.preOrderWhile = function (node) {
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
    return BST;
}());
var bst = new BST();
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
