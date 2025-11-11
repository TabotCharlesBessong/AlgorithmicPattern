package main

import (
	"fmt"
)

func trap(height []int) int {
	if len(height) == 0 {
		return 0
	}

	left, right := 0, len(height)-1
	total := 0
	leftMax := height[left]
	rightMax := height[right]

	for left < right {
		if height[left] < height[right] {
			if height[left] > leftMax {
				leftMax = height[left]
			} else {
				total += leftMax - height[left]
			}
			left++
		} else {
			if height[right] > rightMax {
				rightMax = height[right]
			} else {
				total += rightMax - height[right]
			}
			right--
		}
	}
	return total
}

func main() {
	fmt.Println(trap([]int{0,1,0,2,1,0,1,3,2,1,2,1})) // Output: 6
}
