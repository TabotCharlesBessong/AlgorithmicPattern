import java.util.PriorityQueue;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);

        for (ListNode l : lists) {
            if (l != null) {
                minHeap.add(l);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while (!minHeap.isEmpty()) {
            ListNode node = minHeap.poll();
            curr.next = node;
            curr = node;

            if (node.next != null) {
                minHeap.add(node.next);
            }
        }
        
        return dummy.next;
    }

    // Helper functions to create and print linked lists
    public static ListNode createLinkedList(int[] arr) {
        if (arr.length == 0) return null;
        ListNode head = new ListNode(arr[0]);
        ListNode curr = head;
        for (int i = 1; i < arr.length; i++) {
            curr.next = new ListNode(arr[i]);
            curr = curr.next;
        }
        return head;
    }

    public static void printLinkedList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " -> " : "\n"));
            head = head.next;
        }
    }

    public static void main(String[] args) {
        ListNode[] lists = { createLinkedList(new int[]{1,4,5}), createLinkedList(new int[]{1,3,4}), createLinkedList(new int[]{2,6}) };
        Solution sol = new Solution();
        ListNode mergedHead = sol.mergeKLists(lists);
        printLinkedList(mergedHead);
    }
}
