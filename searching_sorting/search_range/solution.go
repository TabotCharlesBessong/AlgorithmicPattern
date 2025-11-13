package main

import "fmt"

func searchRange(nums []int, target int) []int {
	first := findBound(nums, target, true)
	if first == -1 {
		return []int{-1, -1}
	}
	last := findBound(nums, target, false)
	return []int{first, last}
}

func findBound(nums []int, target int, isFirst bool) int {
	start, end := 0, len(nums)-1

	for start <= end {
		mid := (start + end) / 2

		if nums[mid] == target {
			if isFirst {
				if mid == start || nums[mid-1] != target {
					return mid
				}
				end = mid - 1
			} else {
				if mid == end || nums[mid+1] != target {
					return mid
				}
				start = mid + 1
			}
		} else if nums[mid] > target {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	return -1
}

func main() {
	fmt.Println(searchRange([]int{5, 7, 7, 8, 8, 10}, 8)) // [3 4]
}
