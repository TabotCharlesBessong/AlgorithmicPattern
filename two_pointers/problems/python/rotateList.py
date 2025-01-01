def rotateRight(head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if not head or not head.next or k == 0:
        return head

    # Count the number of nodes and find the tail
    n = 1
    tail = head
    while tail.next:
        tail = tail.next
        n += 1

    # Adjust k to avoid unnecessary rotations
    k %= n
    if k == 0:
        return head

    # Find the new tail: (n - k - 1)th node
    new_tail_position = n - k - 1
    new_tail = head
    for _ in range(new_tail_position):
        new_tail = new_tail.next

    # Perform the rotation
    new_head = new_tail.next
    new_tail.next = None
    tail.next = head

    return new_head
