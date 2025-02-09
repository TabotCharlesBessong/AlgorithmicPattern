class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0, head)
        current = dummy
        
        while current.next:
            if current.next.val == val:
                current.next = current.next.next
            else:
                current = current.next
        
        return dummy.next

# Helper function to create a linked list from an array
def create_linked_list(arr):
    dummy = ListNode()
    current = dummy
    for num in arr:
        current.next = ListNode(num)
        current = current.next
    return dummy.next

# Helper function to print linked list
def print_linked_list(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("null")

# Example usage
solution = Solution()
head = create_linked_list([1, 2, 6, 3, 4, 5, 6])

print("Before removing elements:")
print_linked_list(head)

head = solution.removeElements(head, 6)

print("After removing elements:")
print_linked_list(head)
