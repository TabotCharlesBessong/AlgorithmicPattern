package main

import "fmt"

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	if head == nil || left == right{
		return head
	}

	dummy := &ListNode{0,head}
	prev := dummy

	// move prev to the node before "left" position
	for i := 0; i < left; i++ {
		prev = prev.Next
	}

	curr := prev.Next
	var nextNode *ListNode

	// Reverse the sublist between "left" and "right"
	for i := left; i < right; i++ {
    nextNode = curr.Next
    curr.Next = nextNode.Next
    nextNode.Next = prev.Next
    prev.Next = nextNode
  }

  return dummy.Next
}

// 🔹 Test Case
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
    head := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}

    new_head := reverseBetween(head, 2, 4)
    printList(new_head) // Expected Output: 1 → 4 → 3 → 2 → 5
}