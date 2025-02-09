package main

import "fmt"

func min(a, b int) int {
	if a < b {
    return a
  }
  return b
}

func maxChildrenWithEightDollars(n int, m int) int {
	if n < m {
		return -1
	}

	remainingMoney := n - m
	count := min(remainingMoney/7,m)

	remainingMoney -= count * 7
	m -= count

	if (m == 0 && remainingMoney > 0) || (m == 1 && remainingMoney == 3){
		count--
	}

	return count
}

func main() {
	fmt.Println(maxChildrenWithEightDollars(20, 3)) // Output: 1
	fmt.Println(maxChildrenWithEightDollars(16, 2)) // Output: 2
	fmt.Println(maxChildrenWithEightDollars(2, 2))  // Output: 0
}