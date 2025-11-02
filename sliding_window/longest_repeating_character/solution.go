package main

import (
	"fmt"
)

func characterReplacement(s string, k int) int {
	occurrence := make([]int, 26)
	left, ans, maxOccurrence := 0, 0, 0

	for right := 0; right < len(s); right++ {
		index := int(s[right] - 'A')
		occurrence[index]++
		if occurrence[index] > maxOccurrence {
			maxOccurrence = occurrence[index]
		}

		if right-left+1-maxOccurrence > k {
			occurrence[int(s[left]-'A')]--
			left++
		} else {
			if right-left+1 > ans {
				ans = right - left + 1
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(characterReplacement("AABABBA", 1)) // Output: 4
}
