package main

import (
  "fmt"
  "math"
)

func main() {
	target := 7
  nums := []int{2,3,1,2,4,3}
  answer := minSubArrayLen(target,nums)
  fmt.Println("Maximum subarray sum of size", target, ":", answer)
}

func minSubArrayLen(target int, nums []int) int {
	var sum int
	minLen := 0
	var start int

	for end := 0; end < len(nums); end++ {
		sum += nums[end]

		for sum >= target {
      if minLen == 0 {
        minLen = end - start + 1
      }
      minLen = int(math.Min(float64(minLen),float64(end-start+1)))
			sum -= nums[start]
			start++
    }
	}
	if minLen == 0 {
		return 0 // No subarray sums equal to target found in the given array.
	}
	return minLen
}