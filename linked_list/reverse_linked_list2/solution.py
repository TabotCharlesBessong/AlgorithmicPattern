import sys
sys.stdout.reconfigure(encoding='utf-8')


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if not head or left == right:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        # Move prev to node before left position
        for _ in range(left - 1):
            prev = prev.next

        curr = prev.next
        nextNode = None

        # Reverse sublist from left to right
        for _ in range(right - left):
            nextNode = curr.next
            curr.next = nextNode.next
            nextNode.next = prev.next
            prev.next = nextNode

        return dummy.next

# 🔹 Test Case
def printList(head):
    while head:
        print(head.val, end=" → " if head.next else "\n")
        head = head.next

head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
solution = Solution()
new_head = solution.reverseBetween(head, 2, 4)
printList(new_head)  # Expected Output: 1 → 4 → 3 → 2 → 5
