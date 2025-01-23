const mergeSort = (arr, l, r) => {
  if (l >= r) {
    return arr;
  }
  let mid = Math.floor(l + (r - l) / 2);
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, mid, r);

  return arr;
};

const merge = (arr, l, mid, r) => {
  let tmp = [];
  let index = 0;

  let i = l;
  let iend = mid;
  let j = mid + 1;
  let jend = r;
  while (i <= iend && j <= jend) {
    if (arr[i] < arr[j]) {
      tmp[index++] = arr[i++];
    } else {
      tmp[index++] = arr[j++];
    }
  }

  while (i <= iend) {
    tmp[index++] = arr[i++];
  }
  while (j <= jend) {
    tmp[index++] = arr[j++];
  }

  for (let i = 0; i < tmp.length; ++i) {
    arr[l + i] = tmp[i];
  }
  return arr;
};

console.log(mergeSort([10, 0, 0, 2, -1, 10, 22], 0, 6));
