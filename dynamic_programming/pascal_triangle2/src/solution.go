package main

import "fmt"

func getRow(rowIndex int) []int {
	row := []int{1}
	for i := 1; i <= rowIndex; i++ {
		row = append(row, 1)
		for j := i - 1; j > 0; j-- {
			row[j] = row[j] + row[j - 1]
		}
	}
	return row
}

func main () {
	result := getRow(8)
	fmt.Println(result)
}