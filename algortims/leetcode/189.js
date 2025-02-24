/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (arr, target) {
  if (!arr.length) return [-1, -1];

  let index1 = lowerBound(arr, target);
  let index2 = lowerBound(arr, target + 1) - 1;

  if (index1 < arr.length && arr[index1] == target) {
    return [index1, index2];
  } else {
    return [-1, -1];
  }
};

var lowerBound = function (arr, target) {
  let start = 0;
  let end = arr.length - 1;
  while (start <= end) {
    let mid = parseInt(start + (end - start) / 2);
    if (arr[mid] >= target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
};

console.log(searchRange([1], 1));
