class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapPairs(head):
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    while head and head.next:
        first = head
        second = head.next

        # Swapping
        prev.next = second
        first.next = second.next
        second.next = first

        # Move pointers
        prev = first
        head = first.next

    return dummy.next

# 🔹 Test Case
def print_list(head):
    curr = head
    while curr:
        print(curr.val, end=" → " if curr.next else "\n")
        curr = curr.next

list1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
print_list(swapPairs(list1))  # Output: 2 → 1 → 4 → 3
