package main

import (
	"fmt"
	"strings"
)

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}

	ones := []string{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"}
	teens := []string{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}
	tens := []string{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
	thousands := []string{"", "Thousand", "Million", "Billion"}

	// Helper function to process numbers less than 1000
	var helper func(num int) string
	helper = func(num int) string {
		var result strings.Builder
		if num >= 100 {
			result.WriteString(ones[num/100] + " Hundred ")
			num %= 100
		}
		if num >= 20 {
			result.WriteString(tens[num/10] + " ")
			num %= 10
		}
		if num >= 10 && num < 20 {
			result.WriteString(teens[num-10] + " ")
			return strings.TrimSpace(result.String())
		}
		if num > 0 {
			result.WriteString(ones[num] + " ")
		}
		return strings.TrimSpace(result.String())
	}

	result := ""
	groupIndex := 0

	for num > 0 {
		group := num % 1000
		if group > 0 {
			segment := helper(group)
			if thousands[groupIndex] != "" {
				segment += " " + thousands[groupIndex]
			}
			result = segment + " " + result
		}
		num /= 1000
		groupIndex++
	}

	return strings.TrimSpace(result)
}

func main() {
	// Test cases
	fmt.Println(numberToWords(10))          // Output: "Ten"
	fmt.Println(numberToWords(10000))          // Output: "Ten Thousand"
	fmt.Println(numberToWords(123))         // Output: "One Hundred Twenty Three"
	fmt.Println(numberToWords(12345))       // Output: "Twelve Thousand Three Hundred Forty Five"
	fmt.Println(numberToWords(1234567))     // Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
	fmt.Println(numberToWords(1000000000))  // Output: "One Billion"
}
