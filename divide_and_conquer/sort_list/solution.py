class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
    
def sortList(head: ListNode) -> ListNode:
  if not head or not head.next:
    return head
  
  def get_middle(head):
    slow,fast = head,head.next
    while fast and fast.next:
      slow = slow.next
      fast = fast.next.next
    return slow
  
  def merge(left,right):
    dummy = ListNode(-1)
    current = dummy
    while left and right:
      if left.val <= right.val:
        current.next = left
        left = left.next
      else:
        current.next = right
        right = right.next
      current = current.next
    current.next = left or right
    return dummy.next
  
  mid = get_middle(head)
  left,right = head, mid.next
  mid.next = None
  
  left = sortList(left)
  right = sortList(right)
  
  return merge(left, right)


# print(sortList([4,2,1,3]))