/**
 * @param {number[]} arr
 * @return {number}
 */
var maxSubArray = function (arr) {
  let maxSum = -Infinity;
  let currentSum = 0;
  for (let i = 0; i < arr.length; ++i) {
    currentSum += arr[i];
    maxSum = Math.max(maxSum, currentSum);

    if (currentSum < 0) {
      currentSum = 0;
    }
  }
  return maxSum;
};

console.log(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]));
