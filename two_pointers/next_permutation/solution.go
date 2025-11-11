package main

import "fmt"

func nextPermutation(nums []int) {
	n := len(nums)
	i := n - 2

	// Step 1: Find first decreasing element
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}

	// Step 2: Find element just larger and swap
	if i >= 0 {
		j := n - 1
		for j >= 0 && nums[j] <= nums[i] {
			j--
		}
		swap(nums, i, j)
	}

	// Step 3: Reverse the suffix
	reverse(nums, i+1, n-1)
}

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func reverse(nums []int, left, right int) {
	for left < right {
		swap(nums, left, right)
		left++
		right--
	}
}

func main() {
	arr := []int{1, 2, 3}
	nextPermutation(arr)
	fmt.Println("Next permutation:", arr)
}
