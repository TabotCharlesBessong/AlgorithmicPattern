function searchRange(nums, target) {
  function findBound(nums, target, isFirst) {
    let start = 0;
    let end = nums.length - 1;

    while (start <= end) {
      const mid = Math.floor((start + end) / 2);

      if (nums[mid] === target) {
        if (isFirst) {
          if (mid === start || nums[mid - 1] !== target) {
            return mid;
          }
          end = mid - 1;
        } else {
          if (mid === end || nums[mid + 1] !== target) {
            return mid;
          }
          start = mid + 1;
        }
      } else if (nums[mid] > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    return -1;
  }

  const first = findBound(nums, target, true);
  if (first === -1) return [-1, -1];
  const last = findBound(nums, target, false);
  return [first, last];
}

// Example
console.log(searchRange([5, 7, 7, 8, 8, 10], 8)); // [3, 4]
console.log(searchRange([5, 7, 7, 8, 8, 10], 6)); // [-1, -1]