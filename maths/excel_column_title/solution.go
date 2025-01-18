package main

import "fmt"

func convertToTitle(n int) string {
	result := ""
	for n > 0 {
		n--
    result = string(rune('A'+n%26)) + result
    n /= 26
	}

	return result
}

func main() {
	fmt.Println(convertToTitle(1))
  fmt.Println(convertToTitle(28))
  fmt.Println(convertToTitle(701))
}