
package main

import "fmt"

func containsDuplicate(nums []int) bool {
	seenNumbers := make(map[int]bool)

	for _, num := range nums {
		if seenNumbers[num] {
			return true
		}
		seenNumbers[num] = true
	}
	return false
}

func main() {
	nums := []int{1, 2, 3, 1}
	result := containsDuplicate(nums)
	fmt.Println(result) // Output: true
}