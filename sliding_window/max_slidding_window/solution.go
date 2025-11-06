package main

import "fmt"

func maxSlidingWindow(nums []int, k int) []int {
	if len(nums) == 0 || k <= 0 {
		return []int{}
	}

	deque := []int{}
	result := []int{}

	for i := 0; i < len(nums); i++ {
		// Remove indices outside the current window
		if len(deque) > 0 && deque[0] < i-k+1 {
			deque = deque[1:]
		}

		// Remove smaller elements
		for len(deque) > 0 && nums[deque[len(deque)-1]] < nums[i] {
			deque = deque[:len(deque)-1]
		}

		deque = append(deque, i)

		if i >= k-1 {
			result = append(result, nums[deque[0]])
		}
	}

	return result
}

func main() {
	fmt.Println(maxSlidingWindow([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3)) // Output: [3 3 5 5 6 7]
}
