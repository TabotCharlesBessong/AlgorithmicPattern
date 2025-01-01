
from typing import Optional

class ListNode:
  def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
    self.val = val
    self.next = next


def rotateRightNaive(head: Optional[ListNode], k: int) -> Optional[ListNode]:
  if not head or not head.next or k == 0:
    return head

  # Count the number of nodes
  n = 1
  tail = head
  while tail.next:
    tail = tail.next
    n += 1

  # Adjust k to avoid unnecessary rotations
  k %= n
  if k == 0:
    return head

  # Perform k rotations
  for _ in range(k):
    prev = None
    curr = head
    while curr.next:
      prev = curr
      curr = curr.next
    # Rotate the list
    curr.next = head
    head = curr
    prev.next = None

  return head
  
print(rotateRightNaive([1,2,3,4,5],2))