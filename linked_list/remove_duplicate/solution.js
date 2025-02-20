class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

const deleteDuplicates = function (head) {
  let dummy = new ListNode(0, head);
  let prev = dummy;

  while (head) {
    // Check if it's a start of duplicates
    if (head.next && head.val === head.next.val) {
      // Skip all duplicates
      while (head.next && head.val === head.next.val) {
        head = head.next;
      }
      // Link prev to the next non-duplicate
      prev.next = head.next;
    } else {
      // Move prev pointer if no duplicate
      prev = prev.next;
    }
    head = head.next;
  }
  return dummy.next;
};

// Example Usage:
const head = new ListNode(
  1,
  new ListNode(
    2,
    new ListNode(
      3,
      new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5))))
    )
  )
);

let result = deleteDuplicates(head);

let resArr = [];
while (result) {
  resArr.push(result.val);
  result = result.next;
}
console.log(resArr); // Output: [1, 2, 5]
