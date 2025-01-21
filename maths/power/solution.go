package main

import (
	"fmt"
)

func myPow(x float64, n int) float64 {
	if n < 0 {
		x = 1 / x
		n = -n
	}

	var power func(x float64, n int) float64
	power = func(x float64, n int) float64 {
		if n == 0 {
			return 1
		}
		half := power(x, n / 2)
		if n%2 == 0 {
			return half * half
		}
		return half * half * x
	}

	return power(x, n)
}

func main() {
	fmt.Println(myPow(2.0, 10)) // Output: 1024
	fmt.Println(myPow(2.0, -2)) // Output: 0.25
}
