package main

import "fmt"

func TwoSum(numbers []int, target int) []int {
	left, right := 0, len(numbers)-1

	for left < right {
		sum := numbers[left] + numbers[right]
		if sum == target {
			return []int{left + 1, right + 1}
		} else if sum < target {
			left++
		} else {
			right--
		}
	}
	return []int{-1, -1} // Return -1, -1 if no solution is found
}

// ✅ Example
// fmt.Println(TwoSum([]int{2, 7, 11, 15}, 18)) // Output: [2, 3]
// fmt.Println(TwoSum([]int{1, 2, 3, 4, 6}, 6)) // Output: [1, 4]
// fmt.Println(TwoSum([]int{-1, 0}, -1)) // Output: [1, 2]
func main() {
	// Example usage
	result := TwoSum([]int{2, 7, 11, 15}, 18)
	fmt.Println(result) // Output: [2, 3]
}