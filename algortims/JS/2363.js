/**
 * @param {number[][]} items1
 * @param {number[][]} items2
 * @return {number[][]}
 */
var mergeSimilarItems = function (items1, items2) {
  let obj = {};
  items1.forEach((elem) => {
    obj[elem[0]] = elem[1];
  });
  items2.forEach((elem) => {
    obj[elem[0]] = obj[elem[0]] ? obj[elem[0]] + elem[1] : elem[1];
  });
  console.log(obj);
  let arr = [];
  Object.keys(obj).forEach((key) => {
    arr.push([Number(key), obj[key]]);
  });
  return arr;
};

console.log(
  mergeSimilarItems(
    [
      [1, 3],
      [2, 2],
    ],
    [
      [7, 1],
      [2, 2],
      [1, 4],
    ]
  )
);
