class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        current = head
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        return head

# Helper function to create a linked list from a list
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
sol = Solution()
head = create_linked_list([1, 1, 2, 3, 3])

print("Before removing duplicates:")
print_linked_list(head)

head = sol.deleteDuplicates(head)

print("After removing duplicates:")
print_linked_list(head)
