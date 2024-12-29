function isHappy(n) {
  // Helper function to calculate the next number
  const getNextNumber = (num) => {
    let total = 0;
    while (num > 0) {
      const digit = num % 10;
      total += digit * digit;
      num = Math.floor(num / 10);
    }
    return total;
  };

  let slow = n;
  let fast = getNextNumber(n);

  while (fast !== 1 && slow !== fast) {
    slow = getNextNumber(slow);
    fast = getNextNumber(getNextNumber(fast));
  }

  return fast === 1;
}

// Example usage
console.log(isHappy(28)); // Output: true
