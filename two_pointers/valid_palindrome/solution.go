package main

import (
	"fmt"
	"unicode"
	// "strings"
)

func isPalindrome(s string) bool {
	left, right := 0, len(s)-1

	for left < right {
		leftChar := rune(s[left])
		rightChar := rune(s[right])

		if !unicode.IsLetter(leftChar) && !unicode.IsDigit(leftChar) {
			left++
		} else if !unicode.IsLetter(rightChar) && !unicode.IsDigit(rightChar) {
			right--
		} else {
			if unicode.ToLower(leftChar) != unicode.ToLower(rightChar) {
				return false
			}
			left++
			right--
		}
	}
	return true
}

func main() {
	fmt.Println(isPalindrome("A man, a plan, a canal: Panama")) // true
	fmt.Println(isPalindrome("race a car"))                     // false
}