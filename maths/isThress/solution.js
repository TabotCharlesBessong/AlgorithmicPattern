function isThree(n) {
  let k = Math.sqrt(n);
  if (k !== Math.floor(k)) return false; // Check if n is a perfect square

  for (let i = 2; i <= Math.sqrt(k); i++) {
    if (k % i === 0) return false; // Check if k is prime
  }

  return k > 1; // Ensure k is greater than 1
}

// Example usage
console.log(isThree(9)); // Output: true
console.log(isThree(16)); // Output: false
