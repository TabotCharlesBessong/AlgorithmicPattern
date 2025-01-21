const countPrimes = (n) => {
  if (n <= 2) return 0;

  const isPrime = new Array(n).fill(true)
  isPrime[0] = isPrime[1] = false;

  // gets all the numbers for the multiples starting from the number n * n for example for 2 starting at 2 * 2 which will be 4
  for (let i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      // we will now move from 4 incrementing i which will be 4 + 2 = 6 and marking them as not prime
      for (let j = i * i; j < n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  return isPrime.filter(Boolean).length
}

console.log(countPrimes(50))
console.log(countPrimes(24))