class ListNode {
  constructor(val, next = null) {
    this.val = val;
    this.next = next;
  }
}

function swapPairs(head) {
  let dummy = new ListNode(0);
  dummy.next = head;
  let prev = dummy;

  while (head && head.next) {
    let first = head;
    let second = head.next;

    // Swapping
    prev.next = second;
    first.next = second.next;
    second.next = first;

    // Move pointers
    prev = first;
    head = first.next;
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

let list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,new ListNode))));
let list1 = new ListNode(
  1,
  new ListNode(
    2,
    new ListNode(
      3,
      new ListNode(4, new ListNode(5, new ListNode(6)))
    )
  )
);
let list2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7)))))))
printList(swapPairs(list)); // Output: 2 → 1 → 4 → 3

printList(swapPairs(list1)); // Output: 2 → 1 → 4 → 3 → 5 → 6
printList(swapPairs(list2))