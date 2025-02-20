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
  int getDecimalValue(ListNode *head)
  {
    int result = 0;
    while (head)
    {
      result = (result * 2) + head->val;
      head = head->next;
    }
    return result;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(0);
  head->next->next = new ListNode(1);

  Solution solution;
  cout << solution.getDecimalValue(head) << endl; // Output: 5

  return 0;
}
