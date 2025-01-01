class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

const sortList = (head) => {
  if (!head || !head.next) return head;

  const getMiddle = (head) => {
    let slow = head,
      fast = head.next;
    while (fast && fast.next) {
      slow = slow.next;
      fast = fast.next.next;
    }
    return slow;
  };

  const merge = (left, right) => {
    let dummy = new ListNode(-1),
      current = dummy;
    while (left && right) {
      if (left.val < right.val) {
        current.next = left;
        left = left.next;
      } else {
        current.next = right;
        right = right.next;
      }
      current = current.next;
    }
    current.next = left || right;
    return dummy.next;
  };

  const mid = getMiddle(head);
  const right = mid.next;
  mid.next = null;

  const left = sortList(head);
  const sortedRight = sortList(right);

  return merge(left, sortedRight);
};
