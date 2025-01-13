package main

import (
	"fmt"
)

func trap(height []int) int {
	left, right := 0, len(height)-1
	leftMax, rightMax := 0, 0
	waterTrapped := 0

	for left < right {
		if height[left] < height[right] {
			if height[left] >= leftMax {
				leftMax = height[left]
			} else {
				waterTrapped += leftMax - height[left]
			}
			left++
		} else {
			if height[right] >= rightMax {
				rightMax = height[right]
			} else {
				waterTrapped += rightMax - height[right]
			}
			right--
		}
	}
	return waterTrapped
}

func main() {
	height := []int{4, 2, 0, 3, 2, 5}
	fmt.Println("Water Trapped:", trap(height))
}