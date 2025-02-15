/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var sortColors = function (arr) {
  let j = 0;
  let k = arr.length - 1;
  for (let i = 0; i < arr.length; ++i) {
    if (arr[i] == 0) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      j++;
    } else if (arr[i] == 2 && i < k) {
      [arr[i], arr[k]] = [arr[k], arr[i]];
      i--;
      k--;
    }
  }
  return arr;
};

console.log(sortColors([1, 2, 0]));
