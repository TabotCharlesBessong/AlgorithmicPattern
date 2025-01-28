package main

import "fmt"

func isSubsequence(s string, t string) bool {
	i, j := 0, 0
	for j < len(t) {
		if i < len(s) && s[i] == t[j] {
			i++
		}
		j++
	}
	return i == len(s)
}

func main() {
	fmt.Println(isSubsequence("abc", "ahbgdc")) // true
	fmt.Println(isSubsequence("axc", "ahbgdc")) // false
}
