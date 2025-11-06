package main

import (
	"fmt"
)

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	if len(s) == 1 {
		return 1
	}

	left, right, ans := 0, 0, 0
	set := make(map[byte]bool)

	for right < len(s) {
		c := s[right]
		for set[c] {
			delete(set, s[left])
			left++
		}
		set[c] = true
		if right-left+1 > ans {
			ans = right - left + 1
		}
		right++
	}
	return ans
}

func main() {
	fmt.Println(lengthOfLongestSubstring("bbbbb")) // Output: 1
	fmt.Println(lengthOfLongestSubstring("abcabcbb")) // Output: 3
	fmt.Println(lengthOfLongestSubstring("pwwkew")) // Output: 3
}
