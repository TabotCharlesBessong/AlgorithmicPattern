function containsNearbyDuplicate(nums, k) {
  const set = new Set();

  for (let i = 0; i < nums.length; i++) {
    if (set.has(nums[i])) return true;

    set.add(nums[i]);
    if (set.size > k) {
      set.delete(nums[i - k]);
    }
  }

  return false;
}

// Example usage
const nums = [1, 2, 3, 1, 4, 5];
const k = 3;
const result = containsNearbyDuplicate(nums, k);
console.log(result); // Output: true
