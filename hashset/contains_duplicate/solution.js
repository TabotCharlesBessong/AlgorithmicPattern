const containsDuplicate = (nums) => {
  const numSet = new Set();

  for (const num of nums) {
    if (numSet.has(num)) {
      return true;
    }
    numSet.add(num);
  }
  return false;
};

// Time Complexity: O(n) - We traverse the list once, and each lookup and insertion in the set is O(1) on average.
// Space Complexity: O(n) - In the worst case, we might store all n elements in the set.
// example usage:
console.log(containsDuplicate([1, 2, 3, 1])); // true
console.log(containsDuplicate([1, 2, 3, 4])); // false
console.log(containsDuplicate([1, 1, 1, 1])); // true
