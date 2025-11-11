package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result := [][]int{}

	for i := 0; i < len(nums) && nums[i] <= 0; i++ {
		if i == 0 || nums[i] != nums[i-1] {
			left, right := i+1, len(nums)-1
			for left < right {
				sum := nums[i] + nums[left] + nums[right]
				if sum < 0 {
					left++
				} else if sum > 0 {
					right--
				} else {
					result = append(result, []int{nums[i], nums[left], nums[right]})
					left++
					right--
					for left < right && nums[left] == nums[left-1] {
						left++
					}
				}
			}
		}
	}
	return result
}

func main() {
	fmt.Println(threeSum([]int{-1, 0, 1, 2, -1, -4}))
	// Output: [[-1 -1 2] [-1 0 1]]
}
