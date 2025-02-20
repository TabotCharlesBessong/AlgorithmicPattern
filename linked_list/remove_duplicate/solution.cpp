#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;

    while (head)
    {
      if (head->next && head->val == head->next->val)
      {
        while (head->next && head->val == head->next->val)
        {
          head = head->next;
        }
        prev->next = head->next;
      }
      else
      {
        prev = prev->next;
      }
      head = head->next;
    }
    return dummy->next;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);

  Solution solution;
  ListNode *result = solution.deleteDuplicates(head);

  while (result)
  {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
