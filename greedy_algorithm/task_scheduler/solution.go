package main

import (
	"fmt"
	"sort"
)

func leastInterval(tasks []byte, n int) int {
	freq := make([]int, 26)
	for _, task := range tasks {
		freq[task-'A']++
	}
	sort.Sort(sort.Reverse(sort.IntSlice(freq)))
    
	maxFreq := freq[0]
	countMaxFreq := 0
    
	for _, f := range freq {
		if f == maxFreq {
			countMaxFreq++
		}
	}

	return max((maxFreq-1)*(n+1)+countMaxFreq, len(tasks))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	tasks := []byte{'A', 'A', 'A', 'B', 'B', 'B'}
	n := 2
	fmt.Println(leastInterval(tasks, n)) // Output: 8
}
