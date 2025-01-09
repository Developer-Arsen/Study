/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */

var nextPermutation = function (arr) {
  let i = arr.length - 1;
  while (i > 0 && arr[i] <= arr[i - 1]) {
    i--;
  }
  --i;
  if (i >= 0) {
    let j = arr.length - 1;
    while (arr[j] <= arr[i]) {
      j--;
    }
    [arr[i], arr[j]] = [arr[j], arr[i]];
  }
  return reverse(arr, i + 1 , arr.length - 1);
};

var reverse = (arr, start, end) => {
  while (start < end) {
    [arr[start], arr[end]] = [arr[end], arr[start]];
    start++;
    end--;
  }
  return arr;
};

console.log(nextPermutation([3,2,1]));
