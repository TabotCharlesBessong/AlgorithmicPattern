#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for min heap (priority queue)
struct Compare
{
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val; // Min-heap: smallest value at the top
  }
};

// Function to merge k sorted linked lists
ListNode *mergeKLists(vector<ListNode *> &lists)
{
  priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;

  // Insert first node of each list into the heap
  for (auto list : lists)
  {
    if (list)
    {
      minHeap.push(list);
    }
  }

  // Create a dummy node to ease the merging process
  ListNode *dummy = new ListNode(-1);
  ListNode *tail = dummy;

  while (!minHeap.empty())
  {
    // Extract the smallest node
    ListNode *smallest = minHeap.top();
    minHeap.pop();

    // Debug: Print extracted node value
    cout << "Extracting node: " << smallest->val << endl;

    // Attach to merged list
    tail->next = smallest;
    tail = tail->next;

    // If next node exists, push it into the heap
    if (smallest->next)
    {
      minHeap.push(smallest->next);
    }
  }

  // Get the merged list's head and delete the dummy node
  ListNode *mergedHead = dummy->next;
  delete dummy;
  return mergedHead;
}

// Function to print a linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// Main function to test the code
int main()
{
  // Create sample linked lists
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *l3 = new ListNode(2);
  l3->next = new ListNode(6);

  vector<ListNode *> lists = {l1, l2, l3};

  // Debug: Print input lists
  cout << "Input Lists:" << endl;
  for (int i = 0; i < lists.size(); i++)
  {
    cout << "List " << i + 1 << ": ";
    printList(lists[i]);
  }

  // Merge k sorted lists
  ListNode *mergedHead = mergeKLists(lists);

  // Print merged result
  cout << "\nMerged List: ";
  printList(mergedHead);

  return 0;
}
