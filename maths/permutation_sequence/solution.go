package main

import (
	"fmt"
	"strconv"
)

func getPermutation(n int, k int) string {
	nums := []int{}
	fact := 1
	for i := 1; i <= n; i++ {
		nums = append(nums, i)
		fact *= i
	}

	k-- // Convert to zero-based index
	result := ""
	for i := 0; i < n; i++ {
		fact /= (n - i)
		index := k / fact
		result += strconv.Itoa(nums[index])
		nums = append(nums[:index], nums[index+1:]...)
		k %= fact
	}
	return result
}

func main() {
	fmt.Println(getPermutation(4, 9)) // Output: 2314
}
