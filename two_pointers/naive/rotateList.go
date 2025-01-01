package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRightNaive(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k == 0 {
		return head
	}

	// Count the number of nodes
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

	// Perform k rotations
	for i := 0; i < k; i++ {
		var prev *ListNode
		curr := head

		for curr.Next != nil {
			prev = curr
			curr = curr.Next
		}

		// Rotate the list
		curr.Next = head
		head = curr
		prev.Next = nil
	}

	return head
}
