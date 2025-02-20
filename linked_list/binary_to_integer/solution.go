package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func getDecimalValue(head *ListNode) int{
	decimal := 0
  for head != nil {
    decimal = decimal*2 + head.Val
    head = head.Next
  }
  return decimal
}

func main(){
	head := &ListNode{1, &ListNode{0, &ListNode{1, nil}}}
  fmt.Println(getDecimalValue(head)) // Output: 5
}