package main

import (
	"fmt"
	"sort"
	"math"
)

func minMovesToSeat(seats []int, students []int) int {
	sort.Ints(seats)
	sort.Ints(students)
	
	moves := 0
	for i := 0; i < len(seats); i++ {
		moves += int(math.Abs(float64(seats[i] - students[i])))
	}
	return moves
}

func main() {
	seats := []int{3, 1, 5}
	students := []int{2, 7, 4}
	fmt.Println(minMovesToSeat(seats, students)) // Output: 4
}
