package main

import (
	"container/heap"
	"fmt"
)

type MaxHeap []int64

func (h MaxHeap) Len() int { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j]}
func (h MaxHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
  *h = append(*h, x.(int64))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
  n := len(old)
  x := old[n-1]
  *h = old[0 : n-1]
  return x
}

func findKthLargest(nums []int, k int) int {
	h := &MaxHeap{}
	heap.Init(h)

	for _, num := range nums {
		heap.Push(h,num)
	}
	for i := 0; i < k-1; i++ {
    heap.Pop(h)
  }

	return heap.Pop(h).(int)
}

func main() {
	nums := []int{7, 10, 4, 3, 20, 15, 8, 6}
	k := 3
	fmt.Println(findKthLargest(nums, k)) // Output: 10
}