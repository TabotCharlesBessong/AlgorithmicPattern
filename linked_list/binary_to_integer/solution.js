class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

const getDecimalValue = (head) => {
  let result = 0;
  while (head){
    result = (result << 1) + head.val;
    head = head.next;
  }
  return result;
}

// example usage

const head1 = new ListNode(1);
head1.next = new ListNode(0);
head1.next.next = new ListNode(1);

const head2 = new ListNode(0);

console.log(getDecimalValue(head1)); // Output: 5