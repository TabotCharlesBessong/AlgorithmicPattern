package main

import "fmt"

func countPrimes (n int) int {
	if n <= 2 {
		return 0
	}

	isPrime := make([]bool,n)
	for i := range isPrime {
		isPrime[i] = true
	}
	isPrime[0] , isPrime[1] = false, false

	for p := 2; p * p < n; p++ {
		if isPrime[p] {
			for i := p * p; i < n; i += p {
        isPrime[i] = false
      }
		}
	}

	count := 0
	for _, v := range isPrime {
		if v {
      count++
    }
	}

	return count
}

func main() {
	n1 := 4
	n2 := 70
	fmt.Printf("Number of primes less than %d: %d\n", n1, countPrimes(n1))
	fmt.Printf("Number of primes less than %d: %d\n", n2, countPrimes(n2))
}