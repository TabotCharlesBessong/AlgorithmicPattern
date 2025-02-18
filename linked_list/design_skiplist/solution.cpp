#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX_LEVEL = 16;

struct Node
{
  int val;
  vector<Node *> next;
  Node(int v, int level) : val(v), next(level + 1, nullptr) {}
};

class Skiplist
{
public:
  Skiplist() : head(new Node(-1, MAX_LEVEL)) {}

  bool search(int target)
  {
    Node *curr = head;
    for (int i = MAX_LEVEL; i >= 0; --i)
    {
      while (curr->next[i] && curr->next[i]->val < target)
      {
        curr = curr->next[i];
      }
    }
    curr = curr->next[0];
    return curr && curr->val == target;
  }

  void add(int num)
  {
    int level = randomLevel();
    Node *newNode = new Node(num, level);
    Node *curr = head;
    vector<Node *> update(level + 1, nullptr);

    for (int i = level; i >= 0; --i)
    {
      while (curr->next[i] && curr->next[i]->val < num)
      {
        curr = curr->next[i];
      }
      update[i] = curr;
    }

    for (int i = 0; i <= level; ++i)
    {
      newNode->next[i] = update[i]->next[i];
      update[i]->next[i] = newNode;
    }
  }

  bool erase(int num)
  {
    Node *curr = head;
    vector<Node *> update(MAX_LEVEL + 1, nullptr);
    bool found = false;

    for (int i = MAX_LEVEL; i >= 0; --i)
    {
      while (curr->next[i] && curr->next[i]->val < num)
      {
        curr = curr->next[i];
      }
      update[i] = curr;
    }

    if (curr->next[0] && curr->next[0]->val == num)
    {
      found = true;
      for (int i = 0; i <= MAX_LEVEL; ++i)
      {
        if (update[i]->next[i] && update[i]->next[i]->val == num)
        {
          update[i]->next[i] = update[i]->next[i]->next[i];
        }
      }
    }
    return found;
  }

private:
  Node *head;

  int randomLevel()
  {
    int level = 0;
    while ((rand() % 2) && level < MAX_LEVEL)
    {
      level++;
    }
    return level;
  }
};

int main()
{
  Skiplist skiplist;
  skiplist.add(1);
  skiplist.add(2);
  skiplist.add(3);
  cout << boolalpha << skiplist.search(0) << endl; // false
  skiplist.add(4);
  cout << skiplist.search(1) << endl; // true
  cout << skiplist.search(3) << endl; // true
  cout << skiplist.search(6) << endl; // false
}
