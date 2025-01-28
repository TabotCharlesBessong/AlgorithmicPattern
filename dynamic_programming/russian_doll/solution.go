package main

import (
	"fmt"
	"sort"
)

func maxEnvelopes(envelopes [][]int) int {
	if len(envelopes) == 0 {
		return 0
	}

	// Step 1: Sort envelopes
	sort.Slice(envelopes, func(i, j int) bool {
		if envelopes[i][0] == envelopes[j][0] {
			return envelopes[i][1] > envelopes[j][1] // Sort heights in descending order for same width
		}
		return envelopes[i][0] < envelopes[j][0]
	})

	// Step 2: Extract heights and apply LIS
	heights := make([]int, len(envelopes))
	for i, e := range envelopes {
		heights[i] = e[1]
	}

	dp := []int{}
	for _, h := range heights {
		pos := binarySearch(dp, h)
		if pos == len(dp) {
			dp = append(dp, h)
		} else {
			dp[pos] = h
		}
	}

	return len(dp)
}

func binarySearch(dp []int, target int) int {
	low, high := 0, len(dp)
	for low < high {
		mid := (low + high) / 2
		if dp[mid] < target {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low
}

func main() {
	envelopes := [][]int{
		{5, 4}, {6, 4}, {6, 7}, {2, 3},
	}
	fmt.Println("Maximum number of envelopes:", maxEnvelopes(envelopes))

	envelopes2 := [][]int{
		{1, 1}, {1, 1}, {1, 1},
	}
	fmt.Println("Maximum number of envelopes:", maxEnvelopes(envelopes2))
}
