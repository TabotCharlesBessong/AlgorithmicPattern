def detectCycle(self,head:ListNode) -> ListNode:
  slow, fast = head, head
  
  while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    
    if slow == fast:
      current = head
      while current != slow:
        current = current.next
        slow = slow.next
      return slow
    
  return None