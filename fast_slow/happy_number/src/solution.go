package main

import "fmt"

func isHappy(n int) bool {
	// Helper function to calculate the next number
	getNextNumber := func(num int) int {
		total := 0
		for num > 0 {
			digit := num % 10
			total += digit * digit
			num /= 10
		}
		return total
	}

	slow := n
	fast := getNextNumber(n)

	// Use fast and slow pointer to detect cycle
	for fast != 1 && slow != fast {
		slow = getNextNumber(slow)
		fast = getNextNumber(getNextNumber(fast))
	}

	return fast == 1
}

func main() {
	// Example usage
	fmt.Println(isHappy(28)) // Output: true
}
