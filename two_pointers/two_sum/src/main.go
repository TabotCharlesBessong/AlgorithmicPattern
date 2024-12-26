package main

import (
  "fmt"
)

// two sum in a sorted array

func main() {
  nums := []int{-1, 0, 1, 2, 3, 4, 5}
  target := 3
  answer := twoSum(nums, target)
  fmt.Println("Indices of two numbers that sum up to", target, "are:", answer)
}

func twoSum(nums []int, target int) []int {
	var result []int
  for i := 0; i < len(nums)-1; i++ {
    for j := i + 1; j < len(nums); j++ {
      if nums[i]+nums[j] == target {
        result = []int{i, j}
        break
      }
    }
  }
  return result
}