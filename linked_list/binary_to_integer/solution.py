class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

class Solution:
  def getDecimalValue(self, head: ListNode) -> int:
    result = 0
    while head:
      result = (result * 2) + head.val
      head = head.next
    return result

# Example Usage:
head = ListNode(1, ListNode(0, ListNode(1)))
sol = Solution()
print(sol.getDecimalValue(head))  # Output: 5
