package main

import "fmt"

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)

	for i, num := range nums {
		complement := target - num
		if j, found := m[complement]; found {
			return []int{j, i}
		}
		m[num] = i
	}
	return []int{}
}

func main() {
	nums := []int{-1, 0, 1, 2, 3, 4, 5}
	target := 8
	answer := twoSum(nums, target)
	fmt.Println("Indices of two numbers that sum up to", target, "are:", answer)
}
