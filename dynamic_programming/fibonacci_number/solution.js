var fib = function (n) {
  // if (n === 0) return 0;
  // if (n === 1) return 1;

  // let prev1 = 0,
  //   prev2 = 1;
  // for (let i = 2; i <= n; i++) {
  //   let current = prev1 + prev2;
  //   prev1 = prev2;
  //   prev2 = current;
  // }
  // return prev2;

  if (n === 0) return 0;
  if (n === 1) return 1;

  let dp = new Array(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (let i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
};

// Example Usage
console.log(fib(10)); // Output: 55
