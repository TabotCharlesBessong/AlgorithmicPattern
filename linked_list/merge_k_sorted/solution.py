from heapq import heappush, heappop
from typing import List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists) == 0:
            return None  # Edge case: empty input
        
        minHeap = []
        index = 0  # Tie-breaker index
        
        # Step 1: Push the first node of each list into the heap
        for l in lists:
            if l:
                heappush(minHeap, (l.val, index, l))
                index += 1  # Increment index to keep heap stable
        
        # Dummy head to simplify list construction
        dummy = ListNode(-1)
        tail = dummy

        # Step 2: Process the heap
        while minHeap:
            val, _, node = heappop(minHeap)  # Extract smallest node
            tail.next = node  # Append to result
            tail = tail.next  # Move tail
            
            if node.next:
                heappush(minHeap, (node.next.val, index, node.next))
                index += 1  # Maintain unique index
        
        return dummy.next  # Return merged list without dummy node

# Helper function to print a linked list
def printList(head: Optional[ListNode]):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next

# Test case
l1 = ListNode(1, ListNode(4, ListNode(5)))
l2 = ListNode(1, ListNode(3, ListNode(4)))
l3 = ListNode(2, ListNode(6))

lists = [l1, l2, l3]

solution = Solution()
merged_head = solution.mergeKLists(lists)

# Print the merged list
printList(merged_head)
