#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    if (!head || left == right)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    for (int i = 0; i < left - 1; i++)
    {
      prev = prev->next;
    }

    ListNode *curr = prev->next;
    ListNode *nextNode = nullptr;

    for (int i = 0; i < right - left; i++)
    {
      nextNode = curr->next;
      curr->next = nextNode->next;
      nextNode->next = prev->next;
      prev->next = nextNode;
    }

    return dummy.next;
  }
};

// 🔹 Test Case
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << (head->next ? " → " : "\n");
    head = head->next;
  }
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution solution;
  ListNode *new_head = solution.reverseBetween(head, 2, 4);
  printList(new_head); // Expected Output: 1 → 4 → 3 → 2 → 5
}
