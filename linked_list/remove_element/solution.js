class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

class Solution {
  removeElements(head, val) {
    let dummy = new ListNode(0, head);
    let current = dummy;

    while (current.next !== null) {
      if (current.next.val === val) {
        current.next = current.next.next; // Remove node
      } else {
        current = current.next;
      }
    }
    return dummy.next;
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
let head = createLinkedList([1, 2, 6, 3, 4, 5, 6]);

console.log("Before removing elements:");
printLinkedList(head);

head = solution.removeElements(head, 6);

console.log("After removing elements:");
printLinkedList(head);
