function productExceptSelf(nums) {
  const n = nums.length;
  const answer = Array(n).fill(1);

  // Compute prefix products
  let prefix = 1;
  for (let i = 0; i < n; i++) {
    answer[i] = prefix;
    prefix *= nums[i];
  }

  // Compute suffix products and multiply with prefix
  let suffix = 1;
  for (let i = n - 1; i >= 0; i--) {
    answer[i] *= suffix;
    suffix *= nums[i];
  }

  return answer;
}

// Example usage
console.log(productExceptSelf([1, 2, 3, 4])); // Output: [24, 12, 8, 6]
