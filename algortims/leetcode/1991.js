/**
 * @param {number[]} arr
 * @return {number}
 */
var findMiddleIndex = function (arr) {
  let totalSum = 0;
  for (let i = 0; i < arr.length; ++i) {
    totalSum += arr[i];
  }

  let leftSum = 0;
  for (let i = 0; i < arr.length; ++i) {
    if (leftSum == totalSum - leftSum - arr[i]) {
      return i;
    } else {
        leftSum += arr[i];
    }
  }

  return -1;
};

console.log(findMiddleIndex([4, 0]));
