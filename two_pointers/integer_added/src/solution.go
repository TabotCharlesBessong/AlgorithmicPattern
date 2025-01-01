package main

import (
	"fmt"
	"sort"
)

func main() {
  nums1 := []int{4,20,16,12,8}
	nums2 := []int{14,18,10}
  fmt.Println(findMinimumX(nums1, nums2))
}

func findMinimumX(nums1 []int, nums2 []int) int {
	sort.Ints((nums1))
	sort.Ints((nums2))

	minX := int(^uint(0) >> 1)
	for i:=0; i < 3; i++ {
		x := nums2[0] - nums1[i]
		if isValidX(nums1,nums2,x){
			if x < minX {
				minX = x
			}
		}
	}
	return minX
}

func isValidX(nums1, nums2 []int, x int) bool {
	removedCount := 0
	j := 0

	for i := 0; i < len(nums1); i++ {
		if j < len(nums2) && nums1[i]+x == nums2[j] {
			j++
		} else {
			removedCount++
		}
		if removedCount > 2 {
			return false
		}
	}
	return true
}