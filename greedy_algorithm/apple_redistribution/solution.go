package main

import (
	"fmt"
	"sort"
)

func minimumBoxes(apple []int, capacity []int) int {
	totalApples := 0
	for _, a := range apple {
		totalApples += a
	}

	sort.Sort(sort.Reverse(sort.IntSlice(capacity)))
	boxesUsed := 0

	for _, cap := range capacity {
		totalApples -= cap
		boxesUsed++
		if totalApples <= 0 {
			return boxesUsed
		}
	}

	return boxesUsed
}

func main() {
	apple := []int{1, 3, 2}
	capacity := []int{4, 3, 1, 5, 2}
	fmt.Println(minimumBoxes(apple, capacity)) // Output: 2

	apple1 := []int{4, 5, 6, 7, 8}
	capacity1 := []int{3, 2, 1, 2, 1, 3, 4}
	fmt.Println(minimumBoxes(apple1, capacity1)) // Output: 7
}
