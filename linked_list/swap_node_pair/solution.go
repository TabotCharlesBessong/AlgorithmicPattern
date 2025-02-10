package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	prev := dummy

	for head != nil && head.Next != nil {
		first := head
		second := head.Next

		// Swapping
		prev.Next = second
		first.Next = second.Next
		second.Next = first

		// Move pointers
		prev = first
		head = first.Next
	}

	return dummy.Next
}

// 🔹 Helper function to print list
func printList(head *ListNode) {
	for head != nil {
		fmt.Print(head.Val)
		if head.Next != nil {
			fmt.Print(" → ")
		}
		head = head.Next
	}
	fmt.Println()
}

func main() {
	list := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, nil}}}}
	printList(swapPairs(list)) // Output: 2 → 1 → 4 → 3
}
