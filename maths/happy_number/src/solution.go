package main

import (
  "fmt"
)

func isHappy(n int) bool {
	getNextNumber := func(num int) int {
		sum := 0
    for num > 0 {
      digit := num % 10
      sum += digit * digit
      num /= 10
    }
    return sum
	}

	// using set to track visited number
	visited := make(map[int]bool)

	for !visited[n]{
		visited[n] = true
    n = getNextNumber(n)
		if n == 1 {
      return true
    }
	}
	return false
}

func main() {
  fmt.Println(isHappy(19)) // true
  fmt.Println(isHappy(28))  // true
  fmt.Println(isHappy(37))  // false
}