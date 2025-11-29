package main

import (
	"fmt"
	"sort"
	"strconv"
)

type Solution struct{}

func (Solution) largestNumber(nums []int) string {
	strs := make([]string, len(nums))
	for i, n := range nums {
		strs[i] = strconv.Itoa(n)
	}

	sort.Slice(strs, func(i, j int) bool {
		return strs[i]+strs[j] > strs[j]+strs[i]
	})

	if strs[0] == "0" {
		return "0"
	}

	result := ""
	for _, s := range strs {
		result += s
	}
	return result
}

func main() {
	s := Solution{}
	fmt.Println(s.largestNumber([]int{3, 30, 34, 5, 9}))
}
