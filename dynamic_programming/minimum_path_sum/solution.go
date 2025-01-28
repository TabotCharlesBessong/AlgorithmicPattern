package main

import (
	"fmt"
)

func minPathSum(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 && j == 0 {
				continue
			} else if i == 0 {
				grid[i][j] += grid[i][j-1] // First row
			} else if j == 0 {
				grid[i][j] += grid[i-1][j] // First column
			} else {
				grid[i][j] += min(grid[i-1][j], grid[i][j-1])
			}
		}
	}
	return grid[m-1][n-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Println(minPathSum([][]int{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}})) // 7
	fmt.Println(minPathSum([][]int{{1, 2, 3}, {4, 5, 6}})) // 12
}
