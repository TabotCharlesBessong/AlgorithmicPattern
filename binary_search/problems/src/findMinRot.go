package main

import (
	"fmt"
)

func main() {
	nums := []int{2, 2, 2, 0, 1}
	min := findMin(nums)
	fmt.Println("Minimum element in: ", nums, " is: ", min)
}

func findMin(nums []int) int {
	left, right := 0, len(nums)-1
	for left < right {
		mid := (left + right) / 2
		if nums[mid] > nums[right] {
			left = mid + 1
		} else if nums[mid] < nums[right] {
			right = mid
		} else {
			right--
		}
	}
	return nums[left]
}
