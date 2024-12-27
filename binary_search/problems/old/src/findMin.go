package main

import (
	"fmt"
)

func main() {
	nums := []int{2, 2, 2, 0, 1}
	min := findMin(nums)
	fmt.Println("Minimum element in: ", nums, " is: ", min)
}

func findMin(arr []int) int {
	min := arr[0]
	for _, num := range arr {
		if num < min {
			min = num
		}
	}
	return min
}
