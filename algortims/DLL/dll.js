class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
    this.prev = null;
  }
}

class DLL {
  constructor() {
    this.size = 0;
    this.head = null;
    this.tail = this.head;
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
  }

  popBack() {
    if (!this.head) return;

    this.tail = this.tail.prev;
    if (this.tail) {
      this.tail.next = null;
    }
    this.size--;
  }

  popFront() {
    if (!this.head) return;

    this.head.next.prev = null;
    this.head = this.head.next;
    this.size--;
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
  }

  erase(index) {
    if (!this.head) return;

    let tmp = this.head;
    while (--index) {
      tmp = tmp.next;
    }
    tmp.next.next.prev = tmp;
    tmp.next = tmp.next.next;
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
}

let dll = new DLL();
dll.addBack(2);
dll.addBack(3);
dll.addFront(1);
dll.popFront();
dll.insert(2, 100)
dll.print();
// dll.insert(2, 100)
// dll.print();
// dll.insert(2, 100)
// dll.erase(2)
// dll.print();
dll.printReverse();
