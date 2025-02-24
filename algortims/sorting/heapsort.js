const buildMaxHeap = (arr) => {
  const size = Math.floor(arr.length / 2) - 1;

  for (let i = size; i >= 0; --i) {
    heapify(arr, i, arr.length);
  }
};


const heapSort = (arr) => {
  buildMaxHeap(arr);

  for (let i = arr.length - 1; i > 0; --i) {
    [arr[i], arr[0]] = [arr[0], arr[i]];
    heapify(arr, 0, i);
  }
  console.log(arr);
};

const heapify = (arr, i, n) => {
  const leftI = getLeft(i);
  const rightI = getRight(i);
  let largestIndex = i;

  if (leftI < n && arr[leftI] > arr[largestIndex]) {
    largestIndex = leftI;
  }

  if (rightI < n && arr[rightI] > arr[largestIndex]) {
    largestIndex = rightI;
  }

  if (largestIndex != i) {
    [arr[largestIndex], arr[i]] = [arr[i], arr[largestIndex]];
    heapify(arr, largestIndex, n);
  }
};

const getLeft = (i) => 2 * i + 1;
const getRight = (i) => 2 * i + 2;

const arr = [1, 10, 6, 2, -2, 3];
heapSort(arr);
