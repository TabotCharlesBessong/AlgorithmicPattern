package main

import "fmt"

func containsNearbyDuplicate(nums []int, k int) bool {
	set := make(map[int]bool)

	for i, num := range nums {
		if set[num] {
			return true
		}
		set[num] = true

		if len(set) > k {
			delete(set, nums[i-k])
		}
	}

	return false
}

func main() {
	nums := []int{1, 2, 3, 1, 4, 5}
	k := 3
	result := containsNearbyDuplicate(nums, k)
	fmt.Println(result) // Output: true
}
