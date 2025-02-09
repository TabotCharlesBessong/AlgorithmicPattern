#include <iostream>
#include <vector>
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
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *current = dummy;

    while (current->next != nullptr)
    {
      if (current->next->val == val)
      {
        current->next = current->next->next; // Remove node
      }
      else
      {
        current = current->next;
      }
    }
    return dummy->next;
  }
};

// Helper function to create a linked list from an array
ListNode *createLinkedList(vector<int> arr)
{
  ListNode *dummy = new ListNode(0);
  ListNode *current = dummy;
  for (int num : arr)
  {
    current->next = new ListNode(num);
    current = current->next;
  }
  return dummy->next;
}

// Helper function to print linked list
void printLinkedList(ListNode *head)
{
  while (head != nullptr)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "null" << endl;
}

// Main function for testing
int main()
{
  Solution solution;
  vector<int> arr = {1, 2, 6, 3, 4, 5, 6};
  ListNode *head = createLinkedList(arr);

  cout << "Before removing elements:" << endl;
  printLinkedList(head);

  head = solution.removeElements(head, 6);

  cout << "After removing elements:" << endl;
  printLinkedList(head);
  return 0;
}
