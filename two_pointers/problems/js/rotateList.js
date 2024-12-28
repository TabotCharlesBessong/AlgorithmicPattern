class ListNode {
  constructor(val = 0, next = null) {
    this.val = val; // Number
    this.next = next; // ListNode | null
  }
}


function rotateList(head,k){
  if (!head ||!head.next || k === 0) return head;

  // count the number of nodes in the head and find the tail node
  let count = 1;
  let tail = head;
  while (tail.next) {
    tail = tail.next;
    count++;
  }

  // adjust the value of k to be within the range of 0 to count - 1
  k = k % count;
  if (k === 0) return head;

  // find the new tail node
  let newTailPosition = n - k - 1
  let newTail = head;
  for (let i = 0; i < newTailPosition; i++) {
    newTail = newTail.next;
  }

  // perform the rotate operation

  const newHead = newTail.next
  newTail.next = null
  tail.next = head

  return newHead
}