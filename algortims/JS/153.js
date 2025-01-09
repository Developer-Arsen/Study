/**
 * @param {number[]} arr
 * @return {number}
 */
var findMin = function (arr) {
  let start = 0;
  let end = arr.length - 1;
  let min = Infinity;
  while (start <= end) {
    let mid = parseInt(start + (end - start) / 2);
    min = Math.min(min, arr[mid]);
    if (arr[mid] >= arr[start] && arr[start] > arr[end]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return min;
};

console.log(findMin([5, 1, 2, 3, 4]));
