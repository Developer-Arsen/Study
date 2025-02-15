var singleNumber = function(nums) {
    let n = 0;
    for (let i = 0; i < nums.length; ++i) {
        n ^= nums[i];
    }

    return n;
};

console.log(singleNumber(nums = [2,2,1]))