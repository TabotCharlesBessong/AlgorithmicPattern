package main

import (
	"fmt"
	"strings"
	"unicode"
)

func calculate(s string) int {
	stack := []int{}
	currentNumber := 0
	operation := '+'
	s = strings.ReplaceAll(s," ","")

	for i, char := range s {
		if unicode.IsDigit(char){
			currentNumber = currentNumber*10 + int(char-'0')
		}
		if !unicode.IsDigit(char) || i == len(s)-1 {
			if operation == '+'{
				stack = append(stack, currentNumber)
			}else if operation == '-'{
				stack = append(stack, -currentNumber)
			}else if operation == '*' {
				stack[len(stack)-1] *= currentNumber
			}else if operation == '/' {
				stack[len(stack)-1] /= currentNumber
			}
      operation = char
      currentNumber = 0
		}
	}

	result := 0
	for _, num := range stack {
    result += num
  }

	return result  // return the final result after all operations are performed
}

func main() {
	fmt.Println(calculate("3 + 2 * 2")) // 7
  fmt.Println(calculate("14-3/2")) // 13
  fmt.Println(calculate(" 3+5 / 2 ")) // 5
}