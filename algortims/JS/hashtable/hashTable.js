class Node {
  constructor(value) {
    this.value = value; // The value of the node
    this.next = null; // The pointer to the next node
  }
}

class LinkedList {
  constructor() {
    this.head = null; // The head of the linked list
    this.size = 0; // The size of the linked list
  }

  // Add a node at the beginning
  insertAtHead(value) {
    const newNode = new Node(value);
    newNode.next = this.head;
    this.head = newNode;
    this.size++;
  }

  // Add a node at the end
  insertAtTail(value) {
    const newNode = new Node(value);
    if (!this.head) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = newNode;
    }
    this.size++;
  }

  // Insert a node at a specific position
  insertAt(position, value) {
    if (position < 0 || position > this.size) {
      console.error("Invalid position");
      return;
    }

    const newNode = new Node(value);
    if (position === 0) {
      this.insertAtHead(value);
    } else {
      let current = this.head;
      let previous = null;
      let index = 0;

      while (index < position) {
        previous = current;
        current = current.next;
        index++;
      }

      newNode.next = current;
      previous.next = newNode;
      this.size++;
    }
  }

  // Remove a node by value
  removeByValue(value) {
    if (!this.head) return;

    // If the head node is the one to remove
    if (this.head.value === value) {
      this.head = this.head.next;
      this.size--;
      return;
    }

    let current = this.head;
    let previous = null;

    while (current && current.value !== value) {
      previous = current;
      current = current.next;
    }

    // If the value was found
    if (current) {
      previous.next = current.next;
      this.size--;
    } else {
      console.log("Value not found in the list");
    }
  }

  // Remove a node at a specific position
  removeAt(position) {
    if (position < 0 || position >= this.size) {
      console.error("Invalid position");
      return;
    }

    let current = this.head;
    if (position === 0) {
      this.head = this.head.next;
    } else {
      let previous = null;
      let index = 0;

      while (index < position) {
        previous = current;
        current = current.next;
        index++;
      }

      previous.next = current.next;
    }
    this.size--;
  }

  // Search for a value in the linked list
  search(key) {
    let current = this.head;
    let index = 0;

    while (current) {
      if (current.value.key === key) {
        return current.value.val; // Return the index if found
      }
      current = current.next;
      index++;
    }
    return -1; // Return -1 if not found
  }

  // Print the linked list
  printList() {
    if (!this.head) {
      console.log("The list is empty");
      return;
    }

    let current = this.head;
    let result = "";

    while (current) {
      result += `${current.value} -> `;
      current = current.next;
    }
    result += "null";
    console.log(result);
  }

  getSize() {
    return this.size;
  }
}

class Hashtable {
  constructor() {
    this.LOAD_FACTOR = 0.3;
    this.arr = new Array(7);
  }

  hash(key) {
    const a = 7;
    const b = 3;
    const p = 31;
    if (typeof key == "string") {
      let hashValue = 0;
      for (let i = 0; i < key.length; i++) {
        hashValue += key.charCodeAt(i);
      }
      key = hashValue;
    }

    return Math.floor((a * key + b) % p);
  }

  set(key, val) {
    let hashedKey = this.hash(key);
    let bucket = Math.floor(hashedKey % this.arr.length);

    if (typeof this.arr[bucket] != LinkedList) {
      this.arr[bucket] = new LinkedList();
    }

    let obj = { key, val };
    this.arr[bucket].insertAtHead(obj);
  }

  get(key) {
    let hashedKey = this.hash(key);
    let bucket = Math.floor(hashedKey % this.arr.length);

    if (typeof this.arr[bucket] != "object") {
      return undefined;
    }
    return this.arr[bucket].search(key);
  }

  keyinTable() {}

  has(key) {}
}

const hsh = new Hashtable();
hsh.set("name", "Arsen");
console.log(hsh.get("name"));
