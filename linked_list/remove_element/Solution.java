class ListNode {
  int val;
  ListNode next;

  ListNode(int val) {
    this.val = val;
    this.next = null;
  }
}

class Solution {
  public ListNode removeElements(ListNode head, int val) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode current = dummy;

    while (current.next != null) {
      if (current.next.val == val) {
        current.next = current.next.next;
      } else {
        current = current.next;
      }
    }
    return dummy.next;
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

  // Main function
  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] arr = { 1, 2, 6, 3, 4, 5, 6 };
    ListNode head = createLinkedList(arr);

    System.out.println("Before removing elements:");
    printLinkedList(head);

    head = solution.removeElements(head, 6);

    System.out.println("After removing elements:");
    printLinkedList(head);
  }
}
