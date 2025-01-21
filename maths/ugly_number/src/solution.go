package main

import "fmt"

func isUgly(n int) bool {
	if n <= 0 {
		return false
	}

	for _, factor := range []int{2,3,5}{
		for n%factor == 0 {
      n /= factor
    }
	}
	return n ==1
}

func main() {
	fmt.Println(isUgly(6))
	fmt.Println(isUgly(14))
}