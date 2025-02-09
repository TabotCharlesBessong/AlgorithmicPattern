#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *current = head;
    while (current != nullptr && current->next != nullptr)
    {
      if (current->val == current->next->val)
      {
        current->next = current->next->next;
      }
      else
      {
        current = current->next;
      }
    }
    return head;
  }
};

// Helper function to create a linked list from an array
ListNode *createLinkedList(int arr[], int n)
{
  ListNode *dummy = new ListNode(0);
  ListNode *current = dummy;
  for (int i = 0; i < n; i++)
  {
    current->next = new ListNode(arr[i]);
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

int main()
{
  Solution solution;
  int arr[] = {1, 1, 2, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  ListNode *head = createLinkedList(arr, n);
  cout << "Before removing duplicates:" << endl;
  printLinkedList(head);

  head = solution.deleteDuplicates(head);

  cout << "After removing duplicates:" << endl;
  printLinkedList(head);

  return 0;
}
