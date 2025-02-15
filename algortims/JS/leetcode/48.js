/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
  for (let i = 0; i < matrix.length; ++i) {
    let len = matrix[i].length;
    for (let j = i + 1; j < len; ++j) {
      let temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  reverseRows(matrix);
  print(matrix);
};

var reverseRows = function (matrix) {
  for (let i = 0; i < matrix.length; ++i) {
    let len = matrix[i].length;
    for (let j = 0; j < len / 2; ++j) {
      let temp = matrix[i][j];
      matrix[i][j] = matrix[i][len - j - 1];
      matrix[i][len - j - 1] = temp;
    }
  }
};

var print = function (matrix) {
  for (let i = 0; i < matrix.length; ++i) {
    let str = "";
    for (let j = 0; j < matrix[i].length; ++j) {
      str += matrix[i][j] + " ";
    }
    console.log(str);
  }
};

rotate([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
]);
