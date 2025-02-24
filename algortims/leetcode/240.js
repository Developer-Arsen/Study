/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
  let n = matrix.length;
  let m = matrix[0].length;
  let start = 0;
  let end = m - 1;
  while (start < n && end < m ) {
    console.log(matrix[start][end]);
    if (matrix[start][end] == target) {
      return true;
    } else if (matrix[start][end] > target) {
      end--;
    } else {
      start++;
    }
  }
  return false;
};

console.log(
  searchMatrix(
    [[5],[6]],
    6
  )
);
