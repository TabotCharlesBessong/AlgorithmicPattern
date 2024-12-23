package main

import (
	"fmt"
	"math"
)

func main() {
	k := 6
	nums := []int{8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,2619,-16,6}
	answer := findMaxAvgSlidingWindow(nums, k)
	fmt.Println("Maximum average after removing ", k, "elements:", answer)
}

func findMaxAvgSlidingWindow(nums []int, k int) float64 {
	var windowSum int
	var start int

	max := math.Inf(-1)

	for end := 0; end < len(nums); end++ {
		windowSum += nums[end]

		if(end - start + 1) == k {
			// calculate windown average
			max = math.Max(max,float64(windowSum)/float64(k))
			windowSum -= nums[start]
			start++
		}
	}

	return max
}
