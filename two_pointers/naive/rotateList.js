/**
 * @param {ListNode | null} head
 * @param {number} k
 * @return {ListNode | null}
 */

class ListNode {
  constructor(val = 0, next = null) {
    this.val = val; // Number
    this.next = next; // ListNode | null
  }
}


function rotateRightNaive(head, k) {
  if (!head || !head.next || k === 0) {
    return head;
  }

  // Count the number of nodes
  let n = 1;
  let tail = head;
  while (tail.next) {
    tail = tail.next;
    n++;
  }

  // Adjust k to avoid unnecessary rotations
  k %= n;
  if (k === 0) {
    return head;
  }

  // Perform k rotations
  for (let i = 0; i < k; i++) {
    let prev = null;
    let curr = head;

    while (curr.next) {
      prev = curr;
      curr = curr.next;
    }

    // Rotate the list
    curr.next = head;
    head = curr;
    prev.next = null;
  }

  return head;
}
