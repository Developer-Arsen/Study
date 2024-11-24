class Node {
    constructor(val) {
        this.value_ = val;
        this.next_ = null
        this.prev_ = null;
        this.greater_ = null;
        this.lesser_ = null;
        
    }
}

class FrankensteinList {
    constructor() {
        this.head_ = null;
        this.tail_ = null;
        this.asc_head_ = null;
        this.desc_head_ = null;
        this.length_ = 0;
    }

    push(val) {
        const newNode = new Node(val);
        if (!this.length_) {
            this.head_ = newNode;
            this.tail_ = newNode;
            this.asc_head_ = newNode;
            this.desc_head_ = newNode;
        } else {
            this.tail_.next_ = newNode;
            this.tail_ = newNode;
        }
        this.length_++;
    }

    insert(val) {
        const newNode = new Node(val);
        if (!this.length_) {
            this.head_ = newNode;
            this.tail_ = newNode;
            this.asc_head_ = newNode;
            this.desc_head_ = newNode;
        } else {
            this.tail_.next_ = newNode;
            this.tail_ = newNode;
        }

        this.length_++;
    }

    toString(sort = false, asc = true) {
        let arr = [];
        let current;
        if (sort) {
            if (asc) current = this.asc_head_;
            else current = this.desc_head_;
        } else {
            current = this.head_;
        }

        while (current) {
            arr.push(current.value_);
            current = current.next_;
        }

        return arr.join(" -> ");
    }

    toStringAsc() {
        return this.toString(true);
    }

    toStringDesc() {
        return this.toString(true, false);
    }

    isEmpty () {
        return this.length_ == false;
    }

    size() {
        return this.length_;
    }
}

const list = new FrankensteinList();
list.push(2);
list.push(3);
list.push(-2);
// list.insert(2);
// list.insert(3);
// list.insert(5);
console.log(list.toString());