package main


import "fmt"

func containsNearbyDuplicate(nums []int, k int) bool {
	bool := make(map[int]int)

	for i, num := range nums {
		if idx, exists := seen[num]; exists && i-idx <= k {
			return true
		}
		seen[num] = i 
	}
	return false
}

func main() {
	nums := []int{1, 2, 3, 1}
	k := 3
	fmt.Println(containsNearbyDuplicate(nums, k))  // Output: true
}