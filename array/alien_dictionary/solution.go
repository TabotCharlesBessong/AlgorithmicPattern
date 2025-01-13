package main

import (
	"fmt"
)

func isAlienSorted(words []string, order string) bool {
	charOrder := make(map[rune]int)
	for i, char := range order {
		charOrder[char] = i
	}

	for i := 0; i < len(words)-1; i++ {
		if !inCorrectOrder(words[i], words[i+1], charOrder) {
			return false
		}
	}
	return true
}

func inCorrectOrder(word1, word2 string, charOrder map[rune]int) bool {
	minLength := len(word1)
	if len(word2) < minLength {
		minLength = len(word2)
	}

	for i := 0; i < minLength; i++ {
		if word1[i] != word2[i] {
			return charOrder[rune(word1[i])] < charOrder[rune(word2[i])]
		}
	}

	return len(word1) <= len(word2)
}

func main() {
	words := []string{"hello", "leetcode"}
	order := "hlabcdefgijkmnopqrstuvwxyz"

	if isAlienSorted(words, order) {
		fmt.Println("The words are sorted in the alien dictionary order.")
	} else {
		fmt.Println("The words are NOT sorted in the alien dictionary order.")
	}
}
