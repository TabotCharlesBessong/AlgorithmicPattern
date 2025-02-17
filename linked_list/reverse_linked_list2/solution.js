class ListNode {
  constructor(val, next = null) {
    this.val = val;
    this.next = next;
  }
}

function reverseBetween(head, left, right) {
  if (!head || left === right) return head;

  let dummy = new ListNode(0, head);
  let prev = dummy;

  // Move prev to the node before "left" position
  for (let i = 0; i < left - 1; i++) {
    prev = prev.next;
  }

  let curr = prev.next;
  // let curr = prev
  let nextNode = null;

  // Reverse the sublist between left and right
  for (let i = 0; i < right - left; i++) {
    nextNode = curr.next;
    curr.next = nextNode.next;
    nextNode.next = prev.next;
    prev.next = nextNode;
  }

  return dummy.next;
}

// 🔹 Test Case
function printList(head) {
  let curr = head,
    result = [];
  while (curr) {
    result.push(curr.val);
    curr = curr.next;
  }
  console.log(result.join(" → "));
}

let list = new ListNode(
  1,
  new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))
);

let list1 = new ListNode(
  1,
  new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))
);
printList(reverseBetween(list, 2, 4)); // Output: 1 → 4 → 3 → 2 → 5
printList(reverseBetween(list1,2,5))
