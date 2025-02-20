package main

import "fmt"

type ListNode struct {
	Url  string
	Prev *ListNode
	Next *ListNode
}

type BrowserHistory struct {
	current *ListNode
}

func Constructor(homepage string) BrowserHistory {
	node := &ListNode{Url: homepage}
	return BrowserHistory{current: node}
}

func (this *BrowserHistory) Visit(url string) {
	newNode := &ListNode{Url: url}
	this.current.Next = newNode
	newNode.Prev = this.current
	this.current = newNode
}

func (this *BrowserHistory) Back(steps int) string {
	for steps > 0 && this.current.Prev != nil {
		this.current = this.current.Prev
		steps--
	}
	return this.current.Url
}

func (this *BrowserHistory) Forward(steps int) string {
	for steps > 0 && this.current.Next != nil {
		this.current = this.current.Next
		steps--
	}
	return this.current.Url
}

func main() {
	browserHistory := Constructor("leetcode.com")
	browserHistory.Visit("google.com")
	browserHistory.Visit("facebook.com")
	browserHistory.Visit("youtube.com")
	fmt.Println(browserHistory.Back(1))  // facebook.com
	fmt.Println(browserHistory.Back(1))  // google.com
	fmt.Println(browserHistory.Forward(1)) // facebook.com
	browserHistory.Visit("linkedin.com")
	fmt.Println(browserHistory.Forward(2)) // linkedin.com
	fmt.Println(browserHistory.Back(2))  // google.com
	fmt.Println(browserHistory.Back(7))  // leetcode.com
}
