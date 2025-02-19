package main

import "fmt"

const SIZE = 1000

type Node struct {
	key   int
	value int
	next  *Node
}

type MyHashMap struct {
	buckets []*Node
}

func Constructor() MyHashMap {
	return MyHashMap{buckets: make([]*Node, SIZE)}
}

func (this *MyHashMap) hash(key int) int {
	return key % SIZE
}

func (this *MyHashMap) Put(key int, value int) {
	index := this.hash(key)
	if this.buckets[index] == nil {
		this.buckets[index] = &Node{key, value, nil}
		return
	}
	curr := this.buckets[index]
	for curr != nil {
		if curr.key == key {
			curr.value = value
			return
		}
		if curr.next == nil {
			break
		}
		curr = curr.next
	}
	curr.next = &Node{key, value, nil}
}

func (this *MyHashMap) Get(key int) int {
	index := this.hash(key)
	curr := this.buckets[index]
	for curr != nil {
		if curr.key == key {
			return curr.value
		}
		curr = curr.next
	}
	return -1
}

func (this *MyHashMap) Remove(key int) {
	index := this.hash(key)
	curr := this.buckets[index]
	if curr == nil {
		return
	}
	if curr.key == key {
		this.buckets[index] = curr.next
		return
	}
	prev := curr
	for curr != nil && curr.key != key {
		prev = curr
		curr = curr.next
	}
	if curr != nil {
		prev.next = curr.next
	}
}

func main() {
	hashMap := Constructor()
	hashMap.Put(1, 10)
	hashMap.Put(2, 20)
	fmt.Println(hashMap.Get(1)) // Output: 10
	fmt.Println(hashMap.Get(3)) // Output: -1 (not found)
	hashMap.Put(2, 25)
	fmt.Println(hashMap.Get(2)) // Output: 25
	hashMap.Remove(2)
	fmt.Println(hashMap.Get(2)) // Output: -1 (removed)
}
