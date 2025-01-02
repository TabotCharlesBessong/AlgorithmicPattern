package main

import "fmt"

func searchMatrix(matrix [][]int, target int) bool {
	var helper func(int, int, int, int) bool
	helper = func(rowStart, rowEnd, colStart, colEnd int) bool {
		if rowStart > rowEnd || colStart > colEnd {
			return false
		}

		midRow := (rowStart + rowEnd) / 2
		midCol := (colStart + colEnd) / 2
		midValue := matrix[midRow][midCol]

		if midValue == target {
			return true
		} else if midValue > target {
			return helper(rowStart, midRow-1, colStart, midCol-1) ||
				helper(rowStart, midRow-1, midCol, colEnd) ||
				helper(midRow, rowEnd, colStart, midCol-1)
		} else {
			return helper(midRow+1, rowEnd, midCol+1, colEnd) ||
				helper(rowStart, midRow, midCol+1, colEnd) ||
				helper(midRow+1, rowEnd, colStart, midCol)
		}
	}

	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	return helper(0, len(matrix)-1, 0, len(matrix[0])-1)
}

func main() {
	matrix := [][]int{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	}
	target := 5
	fmt.Println(searchMatrix(matrix, target)) // Output: true
}
