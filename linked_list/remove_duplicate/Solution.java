class ListNode{
  int val;
  ListNode next;
  ListNode(int x) {
    val = x;
    next = null;
  }
}

public class Solution {
  public ListNode deleteDuplicates(ListNode head){
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode current = dummy;

    while (head != null) {
      if (head.next != null && head.val == head.next.val) {
        while (head.next != null && head.val == head.next.val) {
          head = head.next;
        }
        current.next = head.next;
      }else{
        current = current.next;
      }
      head = head.next;
    }
    return dummy.next;
  }

  public static void main(String[] args) {
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    head.next.next.next = new ListNode(3);
    head.next.next.next.next = new ListNode(4);
    head.next.next.next.next.next = new ListNode(4);
    head.next.next.next.next.next.next = new ListNode(5);

    Solution solution = new Solution();
    ListNode result = solution.deleteDuplicates(head);

    while (result != null) {
      System.out.print(result.val + " ");
      result = result.next;
    }
  }
}
