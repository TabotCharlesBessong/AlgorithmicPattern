package main

import (
	"fmt"
	"math/rand"
)

const MAX_LEVEL = 16

type Node struct {
	val  int
	next []*Node
}

type Skiplist struct {
	head *Node
}

func NewNode(val, level int) *Node {
	return &Node{val, make([]*Node, level+1)}
}

func Constructor() Skiplist {
	return Skiplist{head: NewNode(-1, MAX_LEVEL)}
}

func (this *Skiplist) randomLevel() int {
	level := 0
	for rand.Float64() < 0.5 && level < MAX_LEVEL {
		level++
	}
	return level
}

func (this *Skiplist) Search(target int) bool {
	curr := this.head
	for i := MAX_LEVEL; i >= 0; i-- {
		for curr.next[i] != nil && curr.next[i].val < target {
			curr = curr.next[i]
		}
	}
	curr = curr.next[0]
	return curr != nil && curr.val == target
}

func (this *Skiplist) Add(num int) {
	level := this.randomLevel()
	newNode := NewNode(num, level)
	curr := this.head
	update := make([]*Node, level+1)

	for i := level; i >= 0; i-- {
		for curr.next[i] != nil && curr.next[i].val < num {
			curr = curr.next[i]
		}
		update[i] = curr
	}

	for i := 0; i <= level; i++ {
		newNode.next[i] = update[i].next[i]
		update[i].next[i] = newNode
	}
}

func (this *Skiplist) Erase(num int) bool {
	curr := this.head
	update := make([]*Node, MAX_LEVEL+1)
	found := false

	for i := MAX_LEVEL; i >= 0; i-- {
		for curr.next[i] != nil && curr.next[i].val < num {
			curr = curr.next[i]
		}
		update[i] = curr
	}

	if curr.next[0] != nil && curr.next[0].val == num {
		found = true
		for i := 0; i <= MAX_LEVEL; i++ {
			if update[i].next[i] != nil && update[i].next[i].val == num {
				update[i].next[i] = update[i].next[i].next[i]
			}
		}
	}
	return found
}

func main() {
	skiplist := Constructor()
	skiplist.Add(1)
	skiplist.Add(2)
	skiplist.Add(3)
	fmt.Println(skiplist.Search(0)) // False
	skiplist.Add(4)
	fmt.Println(skiplist.Search(1)) // True
	skiplist.Add(5)
	fmt.Println(skiplist.Search(3)) // True
	fmt.Println(skiplist.Search(6)) // False
}
