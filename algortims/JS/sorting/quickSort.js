const quickSort = (arr, low, high) => {
  if (low > high) return;
  let pivot = parition(arr, low, high);
  quickSort(arr, low, pivot - 1);
  quickSort(arr, pivot + 1, high);
};

const parition = (arr, low, high) => {
  let i = low + 1;
  let j = high;
  while (i <= j) {
    if (arr[i] <= arr[low]) {
      i++;
    } else if (arr[j] > arr[low]) {
      j--;
    } else {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      j--;
      i++;
    }
  }
  [arr[j], arr[low]] = [arr[low], arr[j]];
  return j;
};

const paritionWithMedian = (arr, low, high) => {
    let
}

const findMedian = (a, b, c) => {
  if ((a > b && a < c) || (a < b && a > c)) return a;
  if ((b > a && b < c) || (b < a && b > c)) return b;
  return c;
};

let arr = [3, 6, 8, 10, 1, 2, 1];
quickSort(arr, 0, arr.length - 1);
console.log(1 > 5 < 3);
