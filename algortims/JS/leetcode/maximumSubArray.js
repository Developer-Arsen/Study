const findMaximumSubArrayCrossing = (arr, low, mid, high) => {
  let left_sum = -Infinity;
  let left_index = 0;
  let sum = 0;
  for (let i = mid; i > low; --i) {
    sum += arr[i];
    if (left_sum < sum) {
      left_sum = sum;
      left_index = i;
    }
  }

  let right_sum = -Infinity;
  let right_index = 0;
  sum = 0;
  for (let i = mid + 1; i < high; ++i) {
    sum += arr[i];
    if (right_sum < sum) {
      right_sum = sum;
      right_index = i;
    }
  }

  return {
    res_sum: left_sum + right_sum,
    res_low: left_index,
    res_high: right_index,
  };
};

const findMaximumSubArray = (arr, low, high) => {
  if (low == high) {
    return {
      res_sum: arr[low],
      res_low: low,
      res_high: high,
    };
  } else {
    let mid = parseInt(low + (high - low) / 2);
    const {
      res_low: left_low,
      res_high: left_high,
      res_sum: left_sum,
    } = findMaximumSubArray(arr, low, mid);

    const {
      res_low: right_low,
      res_high: right_high,
      res_sum: right_sum,
    } = findMaximumSubArray(arr, mid + 1, high);

    const {
      res_low: cross_low,
      res_high: cross_high,
      res_sum: cross_sum,
    } = findMaximumSubArrayCrossing(arr, low, mid, high);

    if (left_sum >= right_sum && left_sum >= cross_sum) {
      return {
        res_sum: left_sum,
        res_low: left_low,
        res_high: left_high,
      };
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
      return {
        res_sum: right_sum,
        res_low: right_low,
        res_high: right_high,
      };
    } else {
      return {
        res_sum: cross_sum,
        res_low: cross_low,
        res_high: cross_high,
      };
    }
  }
};

const arr = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7];

console.log(findMaximumSubArray(arr, 0, arr.length - 1));
