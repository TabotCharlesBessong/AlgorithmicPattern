package main

import (
	"fmt"
)

type Solution struct {
	values map[string]int
}

func NewSolution() *Solution {
	return &Solution{
		values: map[string]int{
			"I": 1, "V": 5, "X": 10, "L": 50,
			"C": 100, "D": 500, "M": 1000,
			"IV": 4, "IX": 9, "XL": 40, "XC": 90,
			"CD": 400, "CM": 900,
		},
	}
}

func (s *Solution) RomanToInt(str string) int {
	sum := 0
	i := 0
	for i < len(str) {
		if i+1 < len(str) {
			doubleSymbol := str[i : i+2]
			if val, ok := s.values[doubleSymbol]; ok {
				sum += val
				i += 2
				continue
			}
		}
		sum += s.values[string(str[i])]
		i++
	}
	return sum
}

func main() {
	solution := NewSolution()
	fmt.Println(solution.RomanToInt("IX"))     // Output: 9
	fmt.Println(solution.RomanToInt("MCMXCIV")) // Output: 1994
}
