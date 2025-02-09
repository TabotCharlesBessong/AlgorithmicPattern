class ListNode {
  int val;
  ListNode next;

  ListNode(int val) {
    this.val = val;
    this.next = null;
  }
}

class Solution {
  public ListNode deleteDuplicates(ListNode head) {
    ListNode current = head;
    while (current != null && current.next != null) {
      if (current.val == current.next.val) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }
    return head;
  }

  // Helper function to create a linked list from an array
  public static ListNode createLinkedList(int[] arr) {
    ListNode dummy = new ListNode(0);
    ListNode current = dummy;
    for (int num : arr) {
      current.next = new ListNode(num);
      current = current.next;
    }
    return dummy.next;
  }

  // Helper function to print linked list
  public static void printLinkedList(ListNode head) {
    while (head != null) {
      System.out.print(head.val + " -> ");
      head = head.next;
    }
    System.out.println("null");
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] arr = { 1, 1, 2, 3, 3 };

    ListNode head = createLinkedList(arr);
    System.out.println("Before removing duplicates:");
    printLinkedList(head);

    head = solution.deleteDuplicates(head);

    System.out.println("After removing duplicates:");
    printLinkedList(head);
  }
}
