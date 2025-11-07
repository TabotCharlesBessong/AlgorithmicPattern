function threeSum(nums) {
  nums.sort((a, b) => a - b);
  const result = [];

  for (let i = 0; i < nums.length && nums[i] <= 0; i++) {
    if (i === 0 || nums[i] !== nums[i - 1]) {
      let left = i + 1;
      let right = nums.length - 1;

      while (left < right) {
        const sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          result.push([nums[i], nums[left++], nums[right--]]);
          while (left < right && nums[left] === nums[left - 1]) left++;
        }
      }
    }
  }

  return result;
}

// ✅ Example usage
console.log(threeSum([-1, 0, 1, 2, -1, -4]));
// Output: [[-1, -1, 2], [-1, 0, 1]]
