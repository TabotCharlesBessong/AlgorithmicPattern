package linked_list.binary_to_integer;
class ListNode {
  int val;
  ListNode next;

  ListNode(int x) {
    val = x;
    next = null;
  }
}

class Solution {
  public int getDecimalValue(ListNode head) {
    int result = 0;
    while (head != null) {
      result = (result * 2) + head.val;
      head = head.next;
    }
    return result;
  }

  public static void main(String[] args) {
    ListNode head = new ListNode(1);
    head.next = new ListNode(0);
    head.next.next = new ListNode(1);

    Solution solution = new Solution();
    System.out.println(solution.getDecimalValue(head)); // Output: 5
  }
}
