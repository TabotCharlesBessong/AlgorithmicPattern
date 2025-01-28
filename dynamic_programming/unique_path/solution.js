var uniquePaths = function (m, n) {
  let totalSteps = m + n - 2; // Total steps
  let chooseSteps = Math.min(m - 1, n - 1); // Choose the smaller of (m-1) or (n-1)

  let result = 1;
  for (let i = 1; i <= chooseSteps; i++) {
    result *= totalSteps--;
    result = Math.floor(result / i); // Use integer division
  }
  return result;
};

// Test Cases
console.log(uniquePaths(3, 7)); // Output: 28
console.log(uniquePaths(3, 2)); // Output: 3
console.log(uniquePaths(10, 10)); // Output: 48620
