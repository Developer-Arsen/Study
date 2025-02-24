var search = function (nums, target) {
  let start = 0;
  let end = nums.length - 1;
  while (start <= end) {
    let mid = parseInt(start + (end - start) / 2);

    if (nums[mid] == target) return mid;
    if (arr[mid] >= arr[start]) {
      if (arr[mid] > target && arr[start] <= target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else {
      if (arr[mid] < target && arr[end] >= target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
  }

  return -1;
};

console.log(search((nums = [4, 5, 6, 7, 8, 9, 10, 1, 2, 3]), (target = 8)));
