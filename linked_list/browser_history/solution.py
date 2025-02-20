class ListNode:
    def __init__(self, url):
        self.url = url
        self.prev = None
        self.next = None

class BrowserHistory:
    def __init__(self, homepage: str):
        self.current = ListNode(homepage)

    def visit(self, url: str) -> None:
        new_node = ListNode(url)
        self.current.next = new_node
        new_node.prev = self.current
        self.current = new_node

    def back(self, steps: int) -> str:
        while steps > 0 and self.current.prev:
            self.current = self.current.prev
            steps -= 1
        return self.current.url

    def forward(self, steps: int) -> str:
        while steps > 0 and self.current.next:
            self.current = self.current.next
            steps -= 1
        return self.current.url

# Example usage:

browser = BrowserHistory("leetcode.com")
browser.visit("google.com")
browser.visit("facebook.com")
browser.visit("youtube.com")
print(browser.back(2))  # Output: "facebook.com"