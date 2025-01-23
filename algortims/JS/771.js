/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function (jewels, stones) {
  let obj = {};
  let sum = 0;
  jewels.split("").forEach((element) => {
    obj[element] = 1;
  });
  stones.split("").forEach((element) => {
    console.log(obj[element]);
    sum += !!obj[element];
  });
  return sum;
};

console.log(numJewelsInStones("aA", "aAAbbbb"));
