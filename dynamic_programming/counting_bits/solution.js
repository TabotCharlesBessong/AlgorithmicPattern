const countBits = (n) => {
  let ans = new Array(n + 1).fill(0);
  for (let i = 1; i <= n; i++){
    ans[i] = ans[Math.floor(i / 2)] + (i % 2)
  }
  return ans
}

// Example usage
console.log(countBits(2)); // [0, 1, 1]
console.log(countBits(5)); // [0, 1, 1, 2, 1, 2]