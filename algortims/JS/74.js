/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
  let start = 0;
  let n = matrix.length;
  let m = matrix[0].length;
  let end = n * m - 1;

  while (start <= end) {
    let mid = parseInt(start + (end - start) / 2);
    let i = Math.floor(mid / m);
    let j = mid % m;

    if (matrix[i][j] == target) {
      return true;
    } else if (matrix[i][j] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
};

console.log(searchMatrix([[1], [3]], 3));
