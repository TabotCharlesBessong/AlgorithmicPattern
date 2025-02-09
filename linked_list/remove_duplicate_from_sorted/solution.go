package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

type Solution struct{}

func (s Solution) deleteDuplicates(head *ListNode) *ListNode {
	current := head
	for current != nil && current.Next != nil {
		if current.Val == current.Next.Val {
			current.Next = current.Next.Next
		} else {
			current = current.Next
		}
	}
	return head
}

// Helper function to create a linked list from a slice
func createLinkedList(arr []int) *ListNode {
	dummy := &ListNode{}
	current := dummy
	for _, num := range arr {
		current.Next = &ListNode{Val: num}
		current = current.Next
	}
	return dummy.Next
}

// Helper function to print linked list
func printLinkedList(head *ListNode) {
	for head != nil {
		fmt.Printf("%d -> ", head.Val)
		head = head.Next
	}
	fmt.Println("null")
}

func main() {
	solution := Solution{}
	arr := []int{1, 1, 2, 3, 3}

	head := createLinkedList(arr)

	fmt.Println("Before removing duplicates:")
	printLinkedList(head)

	head = solution.deleteDuplicates(head)

	fmt.Println("After removing duplicates:")
	printLinkedList(head)
}
