def middleNode(head):
  if not head or not head.next:
    return head # either we have just 1 or no element
  slow, fast = head, head
  while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    
  return slow