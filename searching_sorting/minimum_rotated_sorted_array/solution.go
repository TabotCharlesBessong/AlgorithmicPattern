package main

import (
	"fmt"
)

func findMin(nums []int) int {
	left, right := 0, len(nums)-1
	ans := nums[0]

	if len(nums) == 1 {
		return nums[0]
	}

	for left <= right {
		if nums[left] < nums[right] {
			if nums[left] < ans {
				ans = nums[left]
			}
		}

		mid := (left + right) / 2
		if nums[mid] < ans {
			ans = nums[mid]
		}

		if nums[left] <= nums[mid] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return ans
}

func main() {
	fmt.Println(findMin([]int{4, 5, 6, 7, 0, 1, 2}))
}
