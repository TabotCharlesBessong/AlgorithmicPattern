package main

import (
	"fmt"
	"math"
)

func isThree(n int) bool {
	k := int(math.Sqrt(float64(n)))
	if k*k != n {
		return false // Check if n is a perfect square
	}

	for i := 2; i <= int(math.Sqrt(float64(k))); i++ {
		if k%i == 0 {
			return false // Check if k is prime
		}
	}

	return k > 1 // Ensure k is greater than 1
}

func main() {
	fmt.Println(isThree(9))  // Output: true
	fmt.Println(isThree(16)) // Output: false
}
