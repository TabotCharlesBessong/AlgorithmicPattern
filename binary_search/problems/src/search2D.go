package main

import (
	"fmt"
)

func main() {
	matrix := [][]int{
		{1, 3, 5},
		{7, 10, 11},
		{12, 16, 20},
	}

	fmt.Println(searchMatrix(matrix, 10))
}

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	left, right := 0, m*n-1

	for left <= right {
		mid := left + (right-left)/2
		row, col := mid/n, mid%n
		midValue := matrix[row][col]

		if midValue == target {
			return true
		} else if midValue < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return false
}
