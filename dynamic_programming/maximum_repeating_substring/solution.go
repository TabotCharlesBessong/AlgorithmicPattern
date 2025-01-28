package main

import (
  "fmt"
  "strings"
)

func maxRepeating(sequence string, word string) int {
	k := 0
	repeatedWord := word

	for strings.Contains(sequence,repeatedWord){
		k++
    repeatedWord = word + repeatedWord
	}

	return k
}

func main() {
	sequence := "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"
  word := "abc"

  fmt.Printf("The maximum repeating substring of '%s' in '%s' is '%s' with a repeating count of %d\n", word, sequence, word+word, maxRepeating(sequence, word))

	fmt.Println(maxRepeating("ababc", "ab")) // Output: 2
	fmt.Println(maxRepeating("ababc", "ba")) // Output: 1
	fmt.Println(maxRepeating("ababc", "ac")) // Output: 0

	fmt.Println(maxRepeating("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc", "abc")) // Output: 1000000000
}