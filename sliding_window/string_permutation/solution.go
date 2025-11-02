package main

import (
	"fmt"
)

func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}

	s1Map := make([]int, 26)
	s2Map := make([]int, 26)

	for i := 0; i < len(s1); i++ {
		s1Map[s1[i]-'a']++
		s2Map[s2[i]-'a']++
	}

	matches := func(a,b []int) bool {
		for i := 0; i < 26; i++ {
			if a[i] != b[i] {
				return false
			}
		}
		return true
	}

	for i := 0; i < len(s2)-len(s1); i++ {
		if matches(s1Map, s2Map) {
			return true
		}
		s2Map[s2[i+len(s1)]-'a']++
		s2Map[s2[i]-'a']--
	}
	return matches(s1Map, s2Map)
}

func main() {
	fmt.Println("=== String Permutation - Test Cases ===")
	fmt.Println(checkInclusion("ab", "eidbaooo")) // true
	fmt.Println(checkInclusion("ab", "eidboaoo")) // false
}