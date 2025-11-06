function twoSum(nums, target) {
  let pointer1 = 0;
  let pointer2 = nums.length - 1;

  while (pointer1 < pointer2) {
    const sum = nums[pointer1] + nums[pointer2];
    if (sum === target) {
      return [pointer1 + 1, pointer2 + 1];
    } else if (sum < target) {
      pointer1++;
    } else {
      pointer2--;
    }
  }
  return [-1, -1];
}

// ✅ Example
console.log(twoSum([2, 7, 11, 15], 18)); // [2, 3]
console.log(twoSum([1, 2, 3, 4, 6], 6)); // [1, 4]
console.log(twoSum([-1, 0], -1)); // [1, 2]