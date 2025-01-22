var fib = function (n) {
  if (n === 0) return 0;
  if (n === 1) return 1;

  let prev1 = 0,
    prev2 = 1;
  for (let i = 2; i <= n; i++) {
    let current = prev1 + prev2;
    prev1 = prev2;
    prev2 = current;
  }
  return prev2;
};

// Example Usage
console.log(fib(10)); // Output: 55
