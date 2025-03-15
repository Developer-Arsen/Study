const bubleSort = (arr) => {
  for (let i = 0; i < arr.length; ++i) {
    let flag = 1;
    for (let j = 0; j < arr.length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
        flag = 0;
      }
    }
    if (flag) break;
  }
};

const selectionSort = (arr) => {
  for (let i = 0; i < arr.length; i++) {
    let minIndex = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
  }
};

const insertionSort = (arr) => {
  for (let i = 1; i < arr.length; i++) {
    const key = arr[i];
    let j = i - 1;
    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
};

const bs = (arr, target) => {
  let l = 0;
  let r = arr.length - 1;
  while (l <= r) {
    let mid = Math.floor(l + (r - l) / 2);

    if (arr[mid] === target) return mid;
    else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return -1;
};

const bsr = (arr, target, l, r) => {
  if (l > r) return -1;

  let mid = Math.floor(l + (r - l) / 2);
  if (arr[mid] === target) return mid;

  if (arr[mid] < target) {
    return bsr(arr, target, mid + 1, r);
  }
  return bsr(arr, target, l, mid - 1);
};

const mergeSort = (arr, l, r) => {
  if (l >= r) return;

  let mid = Math.floor(l + (r - l) / 2);
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, mid, r);
};

const merge = (arr, l, mid, r) => {
  let lstart = l;
  let lend = mid;
  let rstart = mid + 1;
  let rend = r;
  let tmp = [];
  let index = 0;

  while (lstart <= lend && rstart <= rend) {
    if (arr[lstart] < arr[rstart]) {
      tmp[index++] = arr[lstart++];
    } else {
      tmp[index++] = arr[rstart++];
    }
  }

  while (lstart <= lend) {
    tmp[index++] = arr[lstart++];
  }

  while (rstart <= rend) {
    tmp[index++] = arr[rstart++];
  }

  for (let i = 0; i < tmp.length; ++i) {
    arr[l + i] = tmp[i];
  }
};

const quickSort = (arr, l, r) => {
  if (l >= r) return;
  const pivot = partition(arr, l, r);
  quickSort(arr, l, pivot - 1);
  quickSort(arr, pivot + 1, r);
};
const partition = (arr, l, r) => {
  const pivotIndx = Math.floor(Math.random() * (r - l + 1) + l);
  const pivot = arr[pivotIndx];
  [arr[r], arr[pivotIndx]] = [arr[pivotIndx], arr[r]];

  let j = r - 1;
  let i = l;

  while (i <= j) {
    while (i <= j && arr[i] < pivot) i++;
    while (i <= j && arr[j] > pivot) j--;

    if (i <= j) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      i++;
      j--;
    }
  }
  [arr[i], arr[r]] = [arr[r], arr[i]];
  return i;
};

const countingSort = (arr) => {
  const min = Math.min(...arr);
  const max = Math.max(...arr);
  const range = max - min + 1;

  const counter = new Array(range).fill(0);
  arr.forEach((element) => {
    counter[element - min]++;
  });
  for (let i = 1; i < range; ++i) {
    counter[i] += counter[i - 1];
  }
  let newArr = new Array(arr.length);

  for (let i = arr.length - 1; i >= 0; ++i) {
    newArr[counter[arr[i] - min] - 1] = arr[i];
    counter[arr[i] - min]--;
  }
  return newArr;
};

const radixSort = (arr) => {
  const newArr = [...arr];
  const max = Math.max(...arr);

  for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
    radixHelper(newArr, exp);
  }
  return newArr;
};

const radixHelper = (arr, exp) => {
  const counter = new Array(10).fill(0);

  arr.forEach((el) => {
    const digit = Math.floor(el / exp) % 10;
    counter[digit]++;
  });

  for (let i = 1; i < 10; ++i) {
    counter[i] += counter[i - 1];
  }

  const newArr = new Array(arr.length);

  for (let i = arr.length - 1; i >= 0; --i) {
    const digit = Math.floor(arr[i] / exp) % 10;
    newArr[counter[digit] - 1] = arr[i];
    counter[digit]--;
  }

  for (let i = 0; i < arr.length; ++i) {
    arr[i] = newArr[i];
  }
};

// const bucketSort = (arr) => {
//   const min = Math.min(...arr);
//   const max = Math.max(...arr);
//   const bucketCounts = Math.floor(Math.sqrt(arr.length));

//   const buckets = Array.from({ length: bucketCounts }, () => []);
//   const bucketSize = (max - min) / bucketCounts;

//   arr.forEach((el) => {
//     const index = Math.floor((el - min) / bucketSize);
//     buckets[index].push(el);
//   });

//   buckets.forEach((nestedArr) => nestedArr.sort((a, b) => a - b));

//   return buckets.flat();
// };

// let arr = [3, 6, 8, 10, 1, 2, 1];
// console.log(bucketSort(arr));

// const bucketSort = (arr) => {
//   const min = Math.min(...arr);
//   const max = Math.max(...arr);
//   const bucketCounts = Math.floor(Math.sqrt(arr.length));

//   const buckets = Array.from({ length: bucketCounts }, () => []);
//   const bucketSize = (max - min) / bucketCounts;

//   arr.forEach((el) => {
//     const index = Math.floor((el - min) % bucketSize);
//     buckets[index].push(el);
//   });

//   buckets.forEach((nestedArr) => nestedArr.sort((a, b) => a - b));

//   return buckets.flat();
// };

// const arr = [0.42, 0.32, 0.53, 0.16, 0.24, 0.98, 0.45, 0.12];
// console.log(bucketSort(arr));


// Hash function properties
// 1.Determinism
// 2. Unfiromity Distribution
// 3. Non reversability 
// 4. Efficeny 
 