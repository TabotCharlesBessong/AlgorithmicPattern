class ListNode {
  int val;
  ListNode next;

  ListNode(int x) {
    val = x;
    next = null;
  }
}

class Solution {
  public ListNode swapPairs(ListNode head) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode prev = dummy;

    while (head != null && head.next != null) {
      ListNode first = head;
      ListNode second = head.next;

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
  public static void printList(ListNode head) {
    while (head != null) {
      System.out.print(head.val + (head.next != null ? " → " : "\n"));
      head = head.next;
    }
  }

  public static void main(String[] args) {
    Solution sol = new Solution();
    ListNode list = new ListNode(1);
    list.next = new ListNode(2);
    list.next.next = new ListNode(3);
    list.next.next.next = new ListNode(4);

    ListNode result = sol.swapPairs(list);
    printList(result); // Output: 2 → 1 → 4 → 3
  }
}
