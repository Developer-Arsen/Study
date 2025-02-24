const instertionSort = (arr) => {
  for (let i = 1; i < arr.length; ++i) {
    let key = arr[i];
    let j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    if (i != j) {
      arr[j + 1] = key;
    }
  }
  return arr;
};

let arr = [2, 2, 3, 4, 1, 6, 54, 2, 2];
console.log(instertionSort(arr));
