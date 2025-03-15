class PriorityQueue {
  constructor(cmp = (a, b) => a - b) {
    this.arr = [];
    this.cmp = cmp;
  }

  getLeft(i) {
    return i * 2 + 1;
  }

  getRight(i) {
    return i * 2 + 2;
  }
  getParent(i) {
    return Math.floor((i - 1) / 2);
  }
  getSize() {
    return this.arr.length;
  }
  peek() {
    return this.getSize() ? this.arr[0] : null;
  }
  insert(val) {
    this.arr.push(val);
    this.heapifyUp(this.getSize() - 1);
  }

  extract() {
    if (!this.getSize()) return null;
    if (this.getSize() === 1) return this.arr.pop();

    let top = this.arr[0];
    this.arr[0] = this.arr.pop();
    this.heapifyDown(0);
    return top;
  }

  heapifyDown(i) {
    let li = this.getLeft(i);
    let ri = this.getRight(i);
    let si = i;
    while (true) {
      if (li < this.getSize() && this.cmp(this.arr[i], this.arr[si]) < 0) {
        si = li;
      }
      if (ri < this.getSize() && this.cmp(this.arr[i], this.arr[si]) < 0) {
        si = ri;
      }

      if (i == si) break;
      [this.arr[i], this.arr[si]] = [this.arr[si], this.arr[i]];
      i = si;
    }
  }

  heapifyUp(i) {
    let parent = this.getParent(i);
    while (i > 0 && this.cmp(this.arr[i], this.arr[parent]) < 0) {
      [this.arr[i], this.arr[parent]] = [this.arr[parent], this.arr[i]];
      i = parent;
      parent = this.getParent(i);
    }
  }
}

const pq = new PriorityQueue((a, b) => b - a);
pq.insert(10);
pq.insert(5);
pq.insert(20);
pq.insert(30);
pq.insert(50);
pq.insert(1);
console.log(pq.arr)