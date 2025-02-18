package main

import (
	"container/heap"
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type MinHeap []*ListNode

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) { *h = append(*h, x.(*ListNode)) }

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func mergeKLists(lists []*ListNode) *ListNode {
	h := &MinHeap{}
	heap.Init(h)

	for _, list := range lists {
		if list != nil {
			heap.Push(h, list)
		}
	}

	dummy := &ListNode{}
	tail := dummy

	for h.Len() > 0 {
		node := heap.Pop(h).(*ListNode)
		tail.Next = node
		tail = node

		if node.Next != nil {
			heap.Push(h, node.Next)
		}
	}

	return dummy.Next
}

func main() {
	list1 := &ListNode{1, &ListNode{4, &ListNode{5, nil}}}
	list2 := &ListNode{1, &ListNode{3, &ListNode{4, nil}}}
	list3 := &ListNode{2, &ListNode{6, nil}}

	mergedList := mergeKLists([]*ListNode{list1, list2, list3})

	for mergedList != nil {
		fmt.Print(mergedList.Val, " -> ")
		mergedList = mergedList.Next
	}
	fmt.Println("nil")
}
