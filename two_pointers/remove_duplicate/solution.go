package main

import "fmt"

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	writeIndex := 1
	for readIndex := 1; readIndex < len(nums); readIndex++ {
		if nums[readIndex] != nums[readIndex-1] {
			nums[writeIndex] = nums[readIndex]
			writeIndex++
		}
	}
	return writeIndex
}

func main() {
	arr := []int{1, 1, 2, 3, 3}
	length := removeDuplicates(arr)
	fmt.Println("Unique elements:", arr[:length])
	fmt.Println("Count:", length)
}
