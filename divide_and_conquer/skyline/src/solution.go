package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] } // Max-heap
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}
func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

func getSkyline(buildings [][]int) [][]int {
	var events []struct {
		x, h int
	}
	for _, b := range buildings {
		events = append(events, struct {
			x, h int
		}{b[0], -b[2]})
		events = append(events, struct {
			x, h int
		}{b[1], b[2]})
	}
	sort.Slice(events, func(i, j int) bool {
		return events[i].x < events[j].x || (events[i].x == events[j].x && events[i].h < events[j].h)
	})

	activeHeights := &MaxHeap{}
	heap.Init(activeHeights)
	heap.Push(activeHeights, 0)
	prevMaxHeight := 0
	var result [][]int

	for _, e := range events {
		if e.h < 0 {
			heap.Push(activeHeights, -e.h)
		} else {
			// Lazy removal
			for i := 0; i < activeHeights.Len(); i++ {
				if (*activeHeights)[i] == e.h {
					(*activeHeights)[i] = (*activeHeights)[activeHeights.Len()-1]
					*activeHeights = (*activeHeights)[:activeHeights.Len()-1]
					heap.Init(activeHeights)
					break
				}
			}
		}

		currMaxHeight := (*activeHeights)[0]
		if currMaxHeight != prevMaxHeight {
			result = append(result, []int{e.x, currMaxHeight})
			prevMaxHeight = currMaxHeight
		}
	}
	return result
}

func main() {
	buildings := [][]int{
		{2, 9, 10},
		{3, 7, 15},
		{5, 12, 12},
		{15, 20, 10},
		{19, 24, 8},
	}
	result := getSkyline(buildings)
	for _, r := range result {
		fmt.Println(r)
	}
}
