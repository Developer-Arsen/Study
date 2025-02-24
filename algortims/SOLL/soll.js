class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
    this.prev = null;
    this.asc = null;
    this.desc = null;
  }
}

class SOLL {
  constructor() {
    this.size = 0;
    this.head = null;
    this.tail = this.head;
    this.low = null;
    this.high = null;
  }

  addBack(val) {
    let tmp = new Node(val);
    if (this.head) {
      this.tail.next = tmp;
      tmp.prev = this.tail;
      this.tail = this.tail.next;
    } else {
      this.head = tmp;
      this.tail = this.head;
    }
    this.size++;
    this.addItemSorted(tmp);
  }

  addItemSorted(node) {
    if (!this.head.next) {
      this.low = this.head;
      this.high = this.head;
      return;
    }

    if (node.val <= this.low.val) {
      let tmp = this.low;
      tmp.desc = node;
      this.low = node;
      node.desc = null;
      node.asc = tmp;

      if (this.size == 2) {
        this.high.desc = this.low;
      }
      return;
    }

    if (node.val >= this.high.val) {
      let tmp = this.high;
      tmp.asc = node;
      this.high = node;
      node.desc = tmp;

      if (this.size == 2) {
        this.low.asc = this.high;
      }
      return;
    }

    let tmp = this.low;
    let prev = null;
    while (tmp.val <= node.val) {
      prev = tmp;
      tmp = tmp.asc;
    }
    prev.asc = node;
    node.asc = tmp;
    node.desc = prev;
    tmp.desc = node;
  }

  removeElementSorted(node) {
    if (!this.head.next) {
      this.low = this.head;
      this.high = this.head;
      return;
    }

    let tmp = this.low;
    let prev = null;
    while (tmp.asc && tmp.val != node.val) {
      prev = tmp;
      tmp = tmp.asc;
    }
    if (prev) {
      if (tmp.asc) {
        prev.asc = tmp.asc;
        tmp.asc.desc = prev;
      } else {
        prev.asc = null;
        this.high = prev;
      }
    } else {
      tmp = tmp.asc;
      tmp.desc = null;
      this.low = tmp;
    }
  }

  addFront(val) {
    let tmp = new Node(val);
    if (this.head) {
      this.head.prev = tmp;
      tmp.next = this.head;
      this.head = tmp;
    } else {
      this.head = tmp;
      this.tail = this.head;
    }
    this.size++;
    this.addItemSorted(tmp);
  }

  popBack() {
    if (!this.head) return;

    this.removeElementSorted(this.tail);
    this.tail = this.tail.prev;
    if (this.tail) {
      this.tail.next = null;
    }
    this.size--;
  }

  popFront() {
    if (!this.head) return;
    this.removeElementSorted(this.head);

    this.head.next.prev = null;
    this.head = this.head.next;
    this.size--;
  }

  insert(index, val) {
    if (!this.head) return;

    let tmp = this.head;
    while (--index) {
      tmp = tmp.next;
    }
    let tmpNode = new Node(val);
    tmpNode.prev = tmp;
    tmpNode.next = tmp.next;
    tmp.next = tmpNode;

    if (this.tail.next) {
      this.tail = this.tail.next;
    }
    this.size++;
    this.addItemSorted(tmpNode);
  }

  erase(index) {
    if (!this.head) return;

    let tmp = this.head;
    let prev = null;
    while (--index) {
      prev = tmp;
      tmp = tmp.next;
    }
    this.removeElementSorted(tmp);
    if (prev) {
      prev.next = tmp.next;
      if (tmp.next) {
        tmp.prev = prev;
      }
    } else {
      tmp = tmp.next;
      tmp.prev = null;
    }
    // if (tmp.next.next) {
    //   tmp.next.next.prev = tmp;
    //   tmp.next = tmp.next.next;
    // } else {

    // }
    this.size--;
  }

  printReverse() {
    let arr = [];
    let tmp = this.tail;
    while (tmp) {
      arr.push(tmp.val);
      tmp = tmp.prev;
    }
    console.log(arr.join(" -> "));
  }

  print() {
    let arr = [];
    let tmp = this.head;
    while (tmp) {
      arr.push(tmp.val);
      tmp = tmp.next;
    }
    console.log(arr.join(" -> "));
  }

  printAsc() {
    let arr = [];
    let tmp = this.low;
    while (tmp) {
      arr.push(tmp.val);
      tmp = tmp.asc;
    }
    console.log(arr.join(" -> "));
  }

  printDesc() {
    let arr = [];
    let tmp = this.high;
    // console.log(this.high)
    while (tmp) {
      arr.push(tmp.val);
      tmp = tmp.desc;
    }
    console.log(arr.join(" -> "));
  }
}

let dll = new SOLL();
// dll.addBack(5);
dll.addBack(4);
dll.addBack(2);
dll.addBack(3);
dll.addFront(1);
dll.popFront();
dll.popBack();
dll.insert(2, 100);
dll.printAsc();
// dll.printDesc();
dll.print();
// // dll.insert(2, 100)
// // dll.print();
// // dll.insert(2, 100)
dll.erase(2);
dll.printAsc();
// dll.printReverse();
