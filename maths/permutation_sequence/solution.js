function getPermutation(n, k) {
  let nums = [];
  let fact = 1;
  for (let i = 1; i <= n; i++) {
    nums.push(i);
    fact *= i;
  }

  k--; // Convert to zero-based index
  let result = "";
  for (let i = 0; i < n; i++) {
    fact = Math.floor(fact / (n - i));
    let index = Math.floor(k / fact);
    result += nums[index];
    nums.splice(index, 1);
    k %= fact;
  }
  return result;
}

// Example
console.log(getPermutation(4, 9)); // Output: 2314
