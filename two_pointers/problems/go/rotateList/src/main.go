package main

type ListNode struct {
  Val  int
  Next *ListNode
}


func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k == 0 {
		return head
	}

	// Count the number of nodes and find the tail
	n := 1
	tail := head
	for tail.Next != nil {
		tail = tail.Next
		n++
	}

	// Adjust k to avoid unnecessary rotations
	k %= n
	if k == 0 {
		return head
	}

	// Find the new tail: (n - k - 1)th node
	newTailPosition := n - k - 1
	newTail := head
	for i := 0; i < newTailPosition; i++ {
		newTail = newTail.Next
	}

	// Perform the rotation
	newHead := newTail.Next
	newTail.Next = nil
	tail.Next = head

	return newHead
}
