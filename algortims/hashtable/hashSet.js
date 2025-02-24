class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class Set {
  constructor() {
    this.LOAD_FACTOR = 0.3;
    this.arr = new Array(7);
  }

  hash(key) {
    const a = 7;
    const b = 3;
    const p = 31;

    return Math.floor((a * key + b) % p);
  }

  set(key, val) {
    let hashedKey = this.hash(key);
    let bucket = Math.floor(hashedKey % this.arr.length);
    console.log(bucket);
  }

  has(key) {}
}

const hsh = new Set();
hsh.set(1, 10);
hsh.set(2, 10);
hsh.set(100, 10);
