// const bubleSort = (arr) => {
//   for (let i = 0; i < arr.length - 1; ++i) {
//     let flag = 1;
//     for (let j = 0; j < arr.length - i - 1; j++) {
//       if (arr[j] > arr[j + 1]) {
//         [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
//         flag = 0;
//       }
//     }
//     if (flag) return arr;
//   }
// };
// const arr = [20, 44, 2, 5, 1];
// bubleSort(arr);
// console.log(arr);

// const selectionSort = (arr) => {
//   for (let i = 0; i < arr.length - 1; ++i) {
//     let minIndex = i;
//     j = i + 1;
//     while (j < arr.length) {
//       if (arr[j] < arr[minIndex]) {
//         minIndex = j;
//       }
//       j++;
//     }
//     [arr[minIndex], arr[i]] = [arr[i], arr[minIndex]];
//   }
// };

// const arr = [20, 44, 2, 5, 1];
// selectionSort(arr);
// console.log(arr);

// const insertionSort = (arr) => {
//   for (let i = 1; i < arr.length; i++) {
//     let j = i - 1;
//     let key = arr[i];
//     while (j >= 0 && arr[j] > key) {
//       arr[j + 1] = arr[j];
//       j--;
//     }
//     arr[j + 1] = key;
//   }
// };

// const arr = [20, 44, 2, 5, 1];
// insertionSort(arr);
// console.log(arr);

// const mergeSortRecursive = (arr, l, r) => {
//   if (l >= r) {
//     return arr;
//   }

//   let mid = l + Math.floor((r - l) / 2);
//   mergeSort(arr, l, mid);
//   mergeSort(arr, mid + 1, r);
//   merge(arr, l, mid, r);
// };

// const merge = (arr, l, mid, r) => {
//   let tmp = [];
//   let index = 0;

//   let lstart = l;
//   let lend = mid;

//   let rstart = mid + 1;
//   let rend = r;

//   while (lstart <= lend && rstart <= rend) {
//     if (arr[lstart] < arr[rstart]) {
//       tmp[index++] = arr[lstart++];
//     } else {
//       tmp[index++] = arr[rstart++];
//     }
//   }

//   while (lstart <= lend) {
//     tmp[index++] = arr[lstart++];
//   }

//   while (rstart <= rend) {
//     tmp[index++] = arr[rstart++];
//   }

//   for (let i = 0; i < tmp.length; ++i) {
//     arr[i + l] = tmp[i];
//   }
// };

// function mergeSortIterative(arr) {
//   let n = arr.length;

//   // Start with small subarrays of size 1, then 2, then 4, etc.
//   for (let width = 1; width < n; width *= 2) {
//     for (let left = 0; left < n - width; left += 2 * width) {
//       let mid = left + width - 1;
//       let right = Math.min(left + 2 * width - 1, n - 1);
//       console.log(left, mid, right);
//       merge(arr, left, mid, right);
//       console.log(arr);

//     }
//     // width = 1
//     // left = 0;
//     // mid = 0
//     // right =
//   }

//   return arr;
// }

// const arr = [20, 1, 7, 5, 1];
// mergeSortIterative(arr);
// console.log(arr);

// const quickSort = (arr, l, r) => {
//   if (l >= r) {
//     return arr;
//   }
//   const pivotIndex = partition(arr, l, r);
//   quickSort(arr, l, pivotIndex - 1);
//   quickSort(arr, pivotIndex + 1, r);
// };

// const partition = (arr, l, r) => {
//   let pivot = Math.floor(Math.random() * (r - l + 1)) + l;

//   let i = l;
//   let j = r - 1;
//   [arr[pivot], arr[r]] = [arr[r], arr[pivot]];
//   while (i <= j) {
//     if (arr[i] < arr[r]) i++;
//     if (arr[j] > arr[r]) j--;
//     else {
//       [arr[j], arr[i]] = [arr[i], arr[j]];
//       i++;
//       j--;
//     }
//   }
//   [arr[i], arr[r]] = [arr[r], arr[i]];
//   return i;
// };

// const arr = [20, 1, 7, 7, 7, 7, 7, 7, 5, 1];
// quickSort(arr, 0, arr.length - 1);
// console.log(arr);

// const binarySearch = (arr, target) => {
//   let l = 0;
//   let r = arr.length - 1;

//   while (l <= r) {
//     let mid = Math.floor(l + (r - l) / 2);
//     if (arr[mid] == target) return true;
//     if (arr[mid] < target) l = mid + 1;
//     else r = mid - 1;
//   }

//   return false;
// };

// const binarySearchRec = (arr, target, l, r) => {
//   if (l > r) return false;

//   let mid = Math.floor(l + (r - l) / 2);
//   if (arr[mid] == target) return true;

//   if (arr[mid] < target) return binarySearchRec(arr, target, mid + 1, r);
//   return binarySearchRec(arr, target, l, mid - 1);
// };

// const arr = [1, 7, 7, 7, 7, 7, 7, 10, 20];
// console.log(binarySearchRec(arr, 1, 0, arr.length - 1));

// console.log(arr);

// const lower_bound = (arr, target) => {
//   let l = 0;
//   let r = arr.length - 1;

//   while (l <= r) {
//     let mid = Math.floor(l + (r - l) / 2);
//     if (arr[mid] > target) {
//       r = mid;
//     } else {
//       l = mid + 1;
//     }
//   }
//   return l;
// };

// const arr = [1, 1, 1, 1, 7, 7, 7, 7, 7, 7, 10, 20];
// console.log(lower_bound(arr, 7));

// const countingSort = (arr) => {
//   let min = Math.min(...arr);
//   let max = Math.max(...arr);
//   const range = max - min + 1;

//   const counter = new Array(range).fill(0);
//   arr.forEach((element) => counter[element - min]++);

//   for (let i = 1; i < counter.length; ++i) {
//     counter[i] += counter[i - 1];
//   }

//   const newtmp = new Array(arr.length);
//   for (let i = arr.length - 1; i >= 0; i--) {
//     newtmp[counter[arr[i] - min] - 1] = arr[i];
//     counter[arr[i] - min]--;
//   }
//   return newtmp;
// };

// const arr = [2, 4, 1, 1, 6];
// console.log(countingSort(arr));
// console.log(countingSort([2, 4, 1, 1, 6].sort()));

// const bucketSort = (arr) => {
//   const divider = 10;
//   const size = arr.length;
//   let newArr = new Array(Math.floor(size / divider));

//   arr.forEach((element) => {
//     const slot = Math.floor(element / divider);
//     if (newArr[slot]) {
//       newArr[slot].push(element);
//     } else {
//       newArr[slot] = [element];
//     }
//   });
//   let tmp = [];
//   newArr.forEach((element) => (tmp = tmp.concat(element.sort())));
//   return tmp;
// };
// const arr = [1,5,7,8,1,2]
// console.log(bucketSort(arr));

// const count = (arr) => {
//   const min = Math.min(...arr);
//   const max = Math.max(...arr);

//   let range = max - min + 1;

//   let counter = new Array(range).fill(0);
//   arr.forEach((element) => {
//     counter[element - min]++;
//   });

//   for (let i = 1; i < range; ++i) {
//     counter[i] += counter[i - 1];
//   }

//   let newArr = new Array(arr.length);
//   for (let i = arr.length - 1; i >= 0; --i) {
//     newArr[counter[arr[i] - min] - 1] = arr[i];
//     counter[arr[i] - min]--;
//   }
//   return newArr;
// };
// const arr = [2, 4, 1, 1, 6];
// console.log(count(arr));

// const radixSort = (arr) => {
//   const max = Math.max(...arr);

//   for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
//     countingSort(arr, exp);
//   }
// };

// const countingSort = (arr, exp) => {
//   const output = new Array(arr.length).fill(0);
//   const counter = new Array(10).fill(0);

//   arr.forEach((element) => {
//     const digit = Math.floor(element / exp) % 10;
//     counter[digit]++;
//   });

//   for (let i = 1; i < 10; i++) {
//     counter[i] += counter[i - 1];
//   }

//   for (let i = arr.length - 1; i >= 0; --i) {
//     const digit = Math.floor(arr[i] / exp) % 10;
//     output[counter[digit] - 1] = arr[i];
//     counter[digit]--;
//   }

//   output.forEach((element, i) => (arr[i] = element));
// };

// const radixSort = (arr) => {
//   const max = Math.max(...arr);
//   for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
//     countingSort(arr, exp);
//   }
// };

// const countingSort = (arr, exp) => {
//   const counter = new Array(10).fill(0);

//   arr.forEach((element) => {
//     const digit = Math.floor(element / exp) % 10;
//     counter[digit]++;
//   });

//   for (let i = 1; i < 10; ++i) {
//     counter[i] += counter[i - 1];
//   }
//   const output = new Array(arr.length).fill(0);
//   for (let i = arr.length - 1; i >= 0; --i) {
//     const digit = Math.floor(arr[i] / exp) % 10;
//     output[counter[digit] - 1] = arr[i];
//     counter[digit]--;
//   }
//   output.forEach((element, i) => (arr[i] = element));
// };

// const arr = [21, 42, 13, 12, 61];
// console.log(radixSort(arr));
// console.log(arr);

// class Stack {
//   constructor() {
//     this.arr = [];
//   }
//   push(val) {
//     this.arr.push(val);
//   }
//   pop() {
//     if (!this.isEmpty()) {
//       this.arr.pop();
//     } else {
//       return "stack is empty";
//     }
//   }
//   peek() {
//     if (this.isEmpty()) return " stack empty";
//     return this.arr[this.arr.length - 1];
//   }
//   isEmpty() {
//     return this.arr.length == 0;
//   }
//   size() {
//     return this.arr.length;
//   }
// }

// const buildMaxHeap = (arr) => {
//   const size = Math.floor(arr.length / 2) - 1;
//   for (let i = size; i >= 0; --i) {
//     console.log(arr[i]);
//     heapify(arr, i, arr.length - 1);
//   }
// };

// const heapify = (arr, i, n) => {
//   let largestIndex = i;
//   let leftI = getLeft(i);
//   let rightI = getRight(i);

//   if (leftI < n && arr[leftI] < arr[largestIndex]) {
//     largestIndex = leftI;
//   }
//   if (rightI < n && a       rr[rightI] < arr[largestIndex]) {
//     largestIndex = rightI;
//   }
//   if (i != largestIndex) {
//     [arr[i], arr[largestIndex]] = [arr[largestIndex], arr[i]];
//     heapify(arr, largestIndex, n);
//   }
// };

// const getLeft = (i) => i * 2 + 1;
// const getRight = (i) => i * 2 + 2;

// const heapSort = (arr) => {
//   buildMaxHeap(arr);

//   for (let i = arr.length - 1; i > 0; --i) {
//     [arr[0], arr[i]] = [arr[i], arr[0]];
//     heapify(arr, 0, i);
//   }
// };

// const arr = [21, 42, 61, 12, 13];
// console.log(heapSort(arr));
// console.log(arr);

// class PriorityQueue {
//   constructor(comparator = (a, b) => a - b) {
//     this.heap = [];
//     this.compare = comparator;
//   }

//   getParent(i) {
//     return Math.floor((i - 1) / 2);
//   }
//   getLeft(i) {
//     return i * 2 + 1;
//   }
//   getRight(i) {
//     return i * 2 + 2;
//   }

//   insert(val) {
//     this.heap.push(val);
//     this.heapifyUp(this.size() - 1);
//   }
//   isEmpty() {
//     return this.heap.length == 0;
//   }

//   peek() {
//     return this.isEmpty() ? null : this.heap[0];
//   }

//   size() {
//     return this.heap.length;
//   }

//   extract() {
//     if (this.size() == 0) return null;
//     if (this.size() == 1) return this.heap.pop();

//     let top = this.heap[0];
//     this.heap[0] = this.heap.pop();
//     this.heapifyDown(0);
//     return top;
//   }

//   heapifyUp(i) {
//     let parent = this.getParent(i);
//     while (i > 0 && this.compare(this.heap[i], this.heap[parent]) < 0) {
//       [this.heap[i], this.heap[parent]] = [this.heap[parent], this.heap[i]];
//       i = parent;
//       parent = this.getParent(i);
//     }
//   }

//   heapifyDown(i) {
//     const li = this.getLeft(i);
//     const ri = this.getRight(i);
//     let smallest = i;

//     while (true) {
//       if (
//         li < this.size() &&
//         this.compare(this.heap[li], this.heap[smallest]) < 0
//       ) {
//         smallest = li;
//       }
//       if (
//         ri < this.size() &&
//         this.compare(this.heap[ri], this.heap[smallest]) < 0
//       ) {
//         smallest = ri;
//       }

//       if (i == smallest) break;

//       [this.heap[smallest], this.heap[i]] = [this.heap[smallest], this.heap[i]];
//       i = smallest;
//     }
//   }
// }

// const pq = new PriorityQueue((a, b) => b - a); // Default Min Heap (smallest values first)
// pq.insert(10);
// pq.insert(5);
// pq.insert(20);
// pq.insert(1);

// console.log("Min Extracted:", pq.extract()); // Output: 1 (smallest value)
// console.log("Heap after extraction:", pq.heap);

// class Queue {
//   constructor() {
//     this.arr = [];
//   }

//   enqueue(val) {
//     this.arr.push(val);
//   }

//   dequeu() {
//     this.arr.shift()
//   }
// }

// class PriorityQueue {
//   constructor(comparator = (a, b) => a - b) {
//     this.heap = [];
//     this.compare = comparator;
//   }

//   insert (val) {
//     this.heap.push(val);

//   }

//   size() {
//     return this.heap.length;
//   }
// }

// new PriorityQueue((a, b) => b - a);

class PriorityQueue {
  constructor(size = 0, comparator = (a, b) => a - b) {
    this.heap = new Array(size).fill(0);
    this.cmp = comparator;
  } 

  getSize() {
    return this.heap.length;
  }
  isEmpty() {
    return this.heap.length === 0;
  }
  getLeft(i) {
    return 2 * i + 1;
  }
  getRight(i) {
    return 2 * i + 2;
  }
  getParent(i) {
    return Math.floor((i - 1) / 2);
  }

  insert(val) {
    this.heap.push(val);
    this.heapifyUp(this.getSize() - 1);
  }

  extract() {
    if (this.getSize() == 0) return undefined;
    if (this.getSize() == 1) return this.heap.pop();

    let top = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.heapifyDown(0);
    return top;
  }

  heapifyDown(i) {
    while (true) {
      let lI = this.getLeft(i);
      let rI = this.getRight(i);
      let sm = i;
      if (lI < this.getSize() && this.cmp(this.heap[lI], this.heap[sm]) < 0) {
        sm = lI;
      }
      if (rI < this.getSize() && this.cmp(this.heap[rI], this.heap[sm]) < 0) {
        sm = rI;
      }
      if (i == sm) break;
      [arr[i], arr[sm]] = [arr[sm], arr[i]];
      i = sm;
    }
  }
  heapifyUp(i) {
    let pI = this.getParent(i);
    while (i > 0 && this.cmp(this.heap[i], this.heap[pI]) < 0) {
      [this.heap[i], this.heap[pI]] = [this.heap[pI], this.heap[i]];
      i = pI;
      pI = this.getParent(i);
    }
  }
}
