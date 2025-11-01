
package main

import "fmt"

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		// fmt.Println("one")
		return false
	}

	charCount := make([]int, 26)

	for i := 0; i < len(s); i++ {
		charCount[s[i]-'a']++
		charCount[t[i]-'a']--
	}

	for _, count := range charCount {
		if count != 0 {
			// fmt.Println("two")
			return false
		}
	}

	// fmt.Println("three")
	return true
}
func main() {
	s := "anagram"
	t := "nagaram"
	fmt.Println(isAnagram(s, t))
}