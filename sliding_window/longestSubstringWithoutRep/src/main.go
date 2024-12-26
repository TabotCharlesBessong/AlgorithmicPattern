package main

import (
	"fmt"
	"math"
)

func main() {
	s := "pwwkew"
	answer := longestSubstringWithoutRepeat(s)
	fmt.Println("Longest substring without repeat in ", s, " is ", answer)
}

func longestSubstringWithoutRepeat(s string) int {
	charMap := make(map[byte]bool)
	largestSubLen := 0
	start := 0

	for end := range s {
		char := s[end]

		if !charMap[char] {
			charMap[char] = true
			largestSubLen = int(math.Max(float64(largestSubLen),float64(end-start+1)))
		}else{
			for charMap[char]{
				charMap[s[start]] = false
        start++
			}
			charMap[char] = true
		}
	}

	return int(largestSubLen)
}