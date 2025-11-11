function nextPermutation(nums) {
  let n = nums.length;
  let i = n - 2;

  // Step 1: Find first decreasing element
  while (i >= 0 && nums[i] >= nums[i + 1]) {
    i--;
  }

  // Step 2: If found, find element just larger and swap
  if (i >= 0) {
    let j = n - 1;
    while (j >= 0 && nums[j] <= nums[i]) {
      j--;
    }
    [nums[i], nums[j]] = [nums[j], nums[i]];
  }

  // Step 3: Reverse the suffix
  let left = i + 1,
    right = n - 1;
  while (left < right) {
    [nums[left], nums[right]] = [nums[right], nums[left]];
    left++;
    right--;
  }
}

// Example
let arr = [1, 2, 3];
nextPermutation(arr);
console.log("Next permutation:", arr);
