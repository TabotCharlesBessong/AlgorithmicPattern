#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    while (head && head->next)
    {
      ListNode *first = head;
      ListNode *second = head->next;

      // Swapping
      prev->next = second;
      first->next = second->next;
      second->next = first;

      // Move pointers
      prev = first;
      head = first->next;
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
  Solution sol;
  ListNode *list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);
  list->next->next->next = new ListNode(4);

  ListNode *result = sol.swapPairs(list);
  printList(result); // Output: 2 → 1 → 4 → 3

  return 0;
}
