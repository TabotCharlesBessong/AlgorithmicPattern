package main

import (
	"fmt"
	"math"
	"sort"
)

func minCost(arr []int, brr []int, k int) int {
	c1 := 0
	for i := range arr {
		c1 += int(math.Abs(float64(arr[i] - brr[i])))
	}

	// sort both arrays
	sort.Ints(arr)
	sort.Ints(brr)

	c2 := k
	for i := range arr {
		c2 += int(math.Abs(float64(arr[i] - brr[i])))
	}

	return min(c1,c2)
}

func min(a, b int) int {
	if a < b {
    return a
  }
  return b
}

func main() {
	fmt.Println(minCost([]int{-7, 9, 5}, []int{7, -2, -5}, 2)) // Output: 13
	fmt.Println(minCost([]int{2, 1}, []int{2, 1}, 0))          // Output: 0
}