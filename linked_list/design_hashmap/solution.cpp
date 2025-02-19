#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
  int key, value;
  ListNode *next;
  ListNode(int k, int v) : key(k), value(v), next(nullptr) {}
};

class MyHashMap
{
private:
  static const int SIZE = 1000;
  vector<ListNode *> buckets;

  int hash(int key)
  {
    return key % SIZE;
  }

public:
  MyHashMap()
  {
    buckets.resize(SIZE, nullptr);
  }

  void put(int key, int value)
  {
    int index = hash(key);
    if (!buckets[index])
    {
      buckets[index] = new ListNode(key, value);
      return;
    }
    ListNode *curr = buckets[index];
    while (true)
    {
      if (curr->key == key)
      {
        curr->value = value; // Update value
        return;
      }
      if (!curr->next)
        break;
      curr = curr->next;
    }
    curr->next = new ListNode(key, value);
  }

  int get(int key)
  {
    int index = hash(key);
    ListNode *curr = buckets[index];
    while (curr)
    {
      if (curr->key == key)
        return curr->value;
      curr = curr->next;
    }
    return -1;
  }

  void remove(int key)
  {
    int index = hash(key);
    ListNode *curr = buckets[index];
    if (!curr)
      return;

    if (curr->key == key)
    {
      buckets[index] = curr->next;
      delete curr;
      return;
    }

    ListNode *prev = curr;
    while (curr && curr->key != key)
    {
      prev = curr;
      curr = curr->next;
    }
    if (curr)
    {
      prev->next = curr->next;
      delete curr;
    }
  }
};

int main()
{
  MyHashMap hashMap;
  hashMap.put(1, 10);
  hashMap.put(2, 20);
  cout << hashMap.get(1) << endl; // Output: 10
  cout << hashMap.get(3) << endl; // Output: -1
  hashMap.put(2, 25);
  cout << hashMap.get(2) << endl; // Output: 25
  hashMap.remove(2);
  cout << hashMap.get(2) << endl; // Output: -1
  return 0;
}
