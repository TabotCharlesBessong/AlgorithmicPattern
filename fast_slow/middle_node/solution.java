// Runtime: 0 ms, faster than 100.00% of Java online submissions for Middle of the Linked List.
// Time Complexity :  O(n)
// Space Complexity : O(1)
class Solution {
  public ListNode middleNode(ListNode head) {
    // Initialize two pointers p1 and p2 pointing to the head...
    if(head == null || head.next == null) return head;
    ListNode p1 = head;
    ListNode p2 = head;
    while (p2 != null && p2.next != null) {
      // In each iteration, we move p1 one node forward and we move p2 two nodes
      // forward...
      p1 = p1.next;
      p2 = p2.next.next;
    }
    // When p2 reaches the last node, p1 will be exactly at the middle point...
    return p1;
  }
}