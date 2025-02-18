
class MinHeap {
  constructor() {
    this.heap = [];
  }

  push(node) {
    this.heap.push(node);
    this.heap.sort((a, b) => a.val - b.val); // Keep it sorted
  }

  pop() {
    return this.heap.shift(); // Remove and return smallest
  }

  isEmpty() {
    return this.heap.length === 0;
  }
}



class ListNode {
  constructor(val = 0, next = null) {
    this.val = val;
    this.next = next;
  }
}

var mergeKLists = function (lists) {
  if (!lists || lists.length === 0) return null;

  let minHeap = new MinHeap();

  for (let list of lists) {
    if (list) minHeap.push(list);
  }

  let dummy = new ListNode(-1);
  let tail = dummy;

  while (!minHeap.isEmpty()) {
    let smallest = minHeap.pop();
    tail.next = smallest;
    tail = tail.next;

    if (smallest.next) {
      minHeap.push(smallest.next);
    }
  }

  return dummy.next;
};


// Helper function to print a linked list
function printList(head) {
  let result = [];
  while (head) {
    result.push(head.val);
    head = head.next;
  }
  console.log(result.join(" -> "));
}

// Test case
let l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
let l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
let l3 = new ListNode(2, new ListNode(6));

let lists = [l1, l2, l3];

let mergedHead = mergeKLists(lists);
printList(mergedHead);
