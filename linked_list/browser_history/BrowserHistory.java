class ListNode {
  String url;
  ListNode prev, next;
  ListNode(String url) {
    this.url = url;
  }
}

class BrowserHistory {
  ListNode current;
  
  public BrowserHistory(String homepage) {
    current = new ListNode(homepage);
  }
  
  public void visit(String url) {
    ListNode newNode = new ListNode(url);
    current.next = newNode;
    newNode.prev = current;
    current = newNode;
  }
  
  public String back(int steps) {
    while (steps > 0 && current.prev != null) {
      current = current.prev;
      steps--;
    }
    return current.url;
  }
  
  public String forward(int steps) {
    while (steps > 0 && current.next != null) {
      current = current.next;
      steps--;
    }
    return current.url;
  }
}
