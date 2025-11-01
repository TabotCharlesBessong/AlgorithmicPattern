function longestConsecutive(nums) {
  if (nums.length === 0) return 0;

  const numSet = new Set(nums);
  let longestSub = 1;

  for (const num of numSet) {
    if (numSet.has(num - 1)) continue;

    let currentNum = num;
    let currentSub = 1;

    while (numSet.has(currentNum + 1)) {
      currentNum++;
      currentSub++;
    }

    longestSub = Math.max(longestSub, currentSub);
  }

  return longestSub;
}

