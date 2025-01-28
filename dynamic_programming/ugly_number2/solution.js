const nthUglyNumber = (n) => {
  const dp = new Array(n).fill(0)
  dp[0] = 1
  let i2 = 0, i3 = 0, i5 = 0
  for (let i = 1; i < n; i++) {
    const next2 = dp[i2] * 2
    const next3 = dp[i3] * 3
    const next5 = dp[i5] * 5

    dp[i] = Math.min(next2, next3, next5)

    if (dp[i] === next2) i2++
    if (dp[i] === next3) i3++
    if (dp[i] === next5) i5++
  }

  return dp[n - 1]
}

// Example usage
console.log(nthUglyNumber(10)); // Output: 12
console.log(nthUglyNumber(17));  // Output: 27