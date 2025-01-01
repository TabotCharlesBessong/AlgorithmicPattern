#include <iostream>
using namespace std;

class ListNode {
  public:
   int val;
   ListNode* next;
   ListNode(int val = 0, ListNode *next = nullptr) : val(val), next(next) {}
};

class Solution {
  public:
   ListNode* sortList(ListNode* head){
    if (!head ||!head->next) return head;
    auto getMiddle = [](ListNode* head){
      ListNode* slow = head;
      ListNode* fast = head->next;
      while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    };

    auto merge = [](ListNode* left, ListNode* right){
      ListNode dummy(0);
      ListNode* tail = &dummy;
      while(left && right){
        if(left->val < right->val){
          tail->next = left;
          left = left->next;
        } else {
          tail->next = right;
          right = right->next;
        }
        tail = tail->next;
      }
      tail->next = left? left : right;
      return dummy.next;
    };

    ListNode *mid = getMiddle(head);
    ListNode *right = mid->next;
    mid->next = nullptr;

    ListNode *left = sortList(head);
    ListNode *sortedRight = sortList(right);

    return merge(left, sortedRight);
   };
};

// Helper function to print the linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

// Main function
int main()
{
  // Creating a linked list: 4 -> 2 -> 1 -> 3
  ListNode *head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  cout << "Original List: ";
  printList(head);

  // Sorting the linked list
  Solution solution;
  head = solution.sortList(head);

  cout << "Sorted List: ";
  printList(head);

  return 0;
}