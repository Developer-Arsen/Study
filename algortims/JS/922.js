/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortArrayByParityII = function (arr) {
  for (let i = 0; i < arr.length; ++i) {
    let j = arr.length - 1;
    if (i % 2 == 0 && arr[i] % 2 != 0) {
      let tmp = arr[i];
      while (j) {
        if (j % 2 != 0 && arr[j] % 2 == 0) {
          break;
        }
        --j;
      }

      arr[i] = arr[j];
      arr[j] = tmp;
    } else if (i % 2 != 0 && arr[i] % 2 == 0) {
      let tmp = arr[i];
      while (j) {
        if (j % 2 == 0 && arr[j] % 2 != 0) {
          break;
        }
        --j;
      }

      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }
  return arr;
};

console.log(sortArrayByParityII([2, 3, 1, 1, 4, 0, 0, 4, 3, 3]));
