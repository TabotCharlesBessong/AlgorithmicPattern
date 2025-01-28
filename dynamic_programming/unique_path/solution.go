package main

import "fmt"

func uniquePaths(m int, n int) int {
	totalSteps := m + n -2
	chooseSteps := min(m-1,n-1)

	result := 1
	for i := 1; i <= chooseSteps; i++ {
		result *= totalSteps
		result /= i
		totalSteps--
	}

	return result
}

func min(a int,b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Println(uniquePaths(3, 7))  // Output: 28
	fmt.Println(uniquePaths(3, 2))  // Output: 3
	fmt.Println(uniquePaths(10, 10)) // Output: 48620
}