class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

class Solution {
  deleteDuplicates(head) {
    let current = head;
    while (current !== null && current.next !== null) {
      if (current.val === current.next.val) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }
    return head;
  }
}

// Helper function to create a linked list from an array
function createLinkedList(arr) {
  let dummy = new ListNode();
  let current = dummy;
  for (let num of arr) {
    current.next = new ListNode(num);
    current = current.next;
  }
  return dummy.next;
}

// Helper function to print linked list
function printLinkedList(head) {
  let output = [];
  while (head !== null) {
    output.push(head.val);
    head = head.next;
  }
  console.log(output.join(" -> ") + " -> null");
}

// Example usage
const solution = new Solution();
let head = createLinkedList([1, 1, 2, 3, 3]);

console.log("Before removing duplicates:");
printLinkedList(head);

head = solution.deleteDuplicates(head);

console.log("After removing duplicates:");
printLinkedList(head);
