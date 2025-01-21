package main

import "fmt"

func addDigits(num int) int {
	if num == 0 {
		return 0
	}
	return 1 + (num-1)%9
}

func main() {
	num := 38
	fmt.Println("Result:", addDigits(num)) // Output: 2
}
