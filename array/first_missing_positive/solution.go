package main

import (
	"fmt"
	"math"
)

// firstMissingPositiveBruteForce - BRUTE FORCE SOLUTION
//
// Args:
//   nums: slice of integers
//
// Returns:
//   int: first missing positive integer
//
// Time Complexity: O(n²)
// Space Complexity: O(1)
func firstMissingPositiveBruteForce(nums []int) int {
	candidate := 1

	for {
		// Check if candidate exists in array
		found := false
		for _, num := range nums {
			if num == candidate {
				found = true
				break
			}
		}

		// If candidate not found, it's our answer
		if !found {
			return candidate
		}

		candidate++
	}
}

// firstMissingPositive - OPTIMAL SOLUTION using Index as Hash Map
//
// Args:
//   nums: slice of integers
//
// Returns:
//   int: first missing positive integer
//
// Time Complexity: O(n)
// Space Complexity: O(1)
func firstMissingPositive(nums []int) int {
	n := len(nums)

	// Step 1: Check if 1 exists in array
	contains1 := false
	for _, num := range nums {
		if num == 1 {
			contains1 = true
			break
		}
	}

	// If 1 is not present, return 1
	if !contains1 {
		return 1
	}

	// Step 2: Replace numbers <= 0 or > n with 1
	for i := 0; i < n; i++ {
		if nums[i] <= 0 || nums[i] > n {
			nums[i] = 1
		}
	}

	// Step 3: Use array indices as hash map
	// Mark presence of number x by making nums[x-1] negative
	for i := 0; i < n; i++ {
		num := int(math.Abs(float64(nums[i])))
		if num == n {
			nums[0] = -int(math.Abs(float64(nums[0])))
		} else {
			nums[num] = -int(math.Abs(float64(nums[num])))
		}
	}

	// Step 4: Find first positive number (missing positive)
	for i := 1; i < n; i++ {
		if nums[i] > 0 {
			return i
		}
	}

	// Check if n is missing
	if nums[0] > 0 {
		return n
	}

	// All numbers 1 to n are present
	return n + 1
}

// Helper function to create a copy of slice for testing
func copySlice(nums []int) []int {
	result := make([]int, len(nums))
	copy(result, nums)
	return result
}

func main() {
	fmt.Println("=== First Missing Positive - Test Cases ===")

	// Test cases
	testCases := [][]int{
		{1, 2, 0},
		{3, 4, -1, 1},
		{7, 8, 9, 11, 12},
		{},
		{1},
		{2},
		{-1, -2, -3},
		{1, 2, 3, 4, 5},
	}

	expected := []int{3, 2, 1, 1, 2, 1, 1, 6}

	// Test Brute Force
	fmt.Println("Brute Force Results:")
	for i, test := range testCases {
		result := firstMissingPositiveBruteForce(copySlice(test))
		fmt.Printf("Test %d: %v -> %d (expected: %d)\n", i+1, test, result, expected[i])
	}

	// Test Optimal
	fmt.Println("\nOptimal Solution Results:")
	for i, test := range testCases {
		result := firstMissingPositive(copySlice(test))
		fmt.Printf("Test %d: %v -> %d (expected: %d)\n", i+1, test, result, expected[i])
	}
}