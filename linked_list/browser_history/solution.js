class ListNode {
  constructor(url) {
    this.url = url;
    this.next = null;
    this.prev = null;
  }
}

class BrowserHistory {
  constructor(homepage) {
    this.current = new ListNode(homepage)
  }

  visit(url){
    const newNode = new ListNode(url);
    this.current.next = newNode;
    newNode.prev = this.current;
    this.current = newNode;
  }

  back(steps){
    while (steps > 0 && this.current.prev){
      this.current = this.current.prev;
      steps--;
    }
    return this.current.url;
  }

  forward(steps){
    while (steps > 0 && this.current.next){
      this.current = this.current.next;
      steps--;
    }
    return this.current.url;
  }
}

// example usage

const browser = new BrowserHistory("leetcode.com");
browser.visit("google.com");   // You are in "leetcode.com"
browser.visit("facebook.com"); // You are in "google.com"
browser.visit("youtube.com");  // You are in "facebook.com"
browser.back(1);           // You are in "google.com" (current page is now "leetcode.com")

console.log(browser.forward(1));    // You are in "facebook.com" (current page is now "youtube.com")