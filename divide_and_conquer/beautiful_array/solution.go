package main

import "fmt"

func beautifulArray(n int) []int {
	if n == 1 {
		return []int{1}
	}

	odd := beautifulArray((n + 1) / 2) // solve for odd indices
	even := beautifulArray(n / 2)      // solve for even indices

	result := make([]int, 0, n)
	for _, x := range odd {
		result = append(result, 2*x-1)
	}
	for _, x := range even {
		result = append(result, 2*x)
	}

	return result
}

func main() {
	fmt.Println(beautifulArray((11)))
}
