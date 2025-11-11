function removeDuplicates(nums) {
  if (nums.length === 0) return 0;

  let writeIndex = 1;

  for (let readIndex = 1; readIndex < nums.length; readIndex++) {
    if (nums[readIndex] !== nums[readIndex - 1]) {
      nums[writeIndex] = nums[readIndex];
      writeIndex++;
    }
  }

  return writeIndex;
}

// Example
const arr = [1, 1, 2, 3, 3];
const len = removeDuplicates(arr);
console.log("Unique elements:", arr.slice(0, len));
console.log("Count:", len);
