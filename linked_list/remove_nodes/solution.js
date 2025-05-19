class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

// Function to remove nodes
var removeNodes = function (head) {
  let prev = null;
  let curr = head;
  while (curr) {
    let nextNode = curr.next;
    curr.next = prev;
    prev = curr;
    curr = nextNode;
  }
  head = prev;

  let maxVal = head.val;
  let dummy = new ListNode(0, head);
  curr = head;
  while (curr && curr.next) {
    if (curr.next.val < maxVal) {
      curr.next = curr.next.next;
    } else {
      curr = curr.next;
      maxVal = curr.val;
    }
  }

  prev = null;
  curr = dummy.next;
  while (curr) {
    let nextNode = curr.next;
    curr.next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
};

// Function to print linked list
function printList(head) {
  let result = [];
  while (head) {
    result.push(head.val);
    head = head.next;
  }
  console.log(result.join(" -> "));
}

// Main Function for Testing
function main() {
  // Creating Linked List: [5, 2, 13, 3, 8]
  let head = new ListNode(
    5,
    new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8))))
  );
  console.log("Original List:");
  printList(head);

  head = removeNodes(head);
  console.log("After Removing Nodes:");
  printList(head);
}

main();
