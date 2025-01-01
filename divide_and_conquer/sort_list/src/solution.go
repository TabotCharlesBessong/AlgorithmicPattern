package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil{
		return head
	}

	getMiddle := func(head *ListNode) *ListNode {
		slow, fast := head, head.Next
    for fast!=nil && fast.Next!=nil {
      slow = slow.Next
      fast = fast.Next.Next
    }
    return slow
	}

	merge := func(left,right *ListNode) *ListNode {
		dummy := &ListNode{}
		current := dummy
		for left!=nil && right!=nil {
			if left.Val < right.Val {
        current.Next = left
        left = left.Next
      } else {
        current.Next = right
        right = right.Next
      }
      current = current.Next
		}
		if left!=nil {
      current.Next = left
    } else {
      current.Next = right
    }
		return dummy.Next
	}

	mid := getMiddle(head)
	right := mid.Next
	mid.Next = nil

	left := sortList(head)
	sortedRight := sortList(right)

	return merge(left,sortedRight)
}

// Helper function to print the linked list
func printList(head *ListNode) {
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
	fmt.Println()
}

// Main function
func main() {
	// Creating a linked list: 4 -> 2 -> 1 -> 3
	head := &ListNode{Val: 4}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 1}
	head.Next.Next.Next = &ListNode{Val: 3}

	fmt.Println("Original List:")
	printList(head)

	// Sorting the linked list
	head = sortList(head)

	fmt.Println("Sorted List:")
	printList(head)
}