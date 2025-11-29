function majorityElement(nums) {
  const counts = {};

  // Count occurrences
  for (const num of nums) {
    if (!(num in counts)) {
      counts[num] = 0;
    }
    counts[num]++;
  }

  // Find majority element
  let majorityKey = null;
  for (const key in counts) {
    if (majorityKey === null || counts[key] > counts[majorityKey]) {
      majorityKey = key;
    }
  }

  return parseInt(majorityKey);
}

// Example
console.log(majorityElement([3, 2, 3]));
console.log(majorityElement([2, 2, 1, 1, 1, 2, 2]));