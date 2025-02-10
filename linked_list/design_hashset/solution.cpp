#include <iostream>
#include <vector>

using namespace std;

class MyHashSet
{
private:
  static const int SIZE = 10007;
  vector<int> buckets[SIZE];

  int _hash(int key)
  {
    return key % SIZE;
  }

public:
  MyHashSet() {}

  void add(int key)
  {
    int index = _hash(key);
    for (int num : buckets[index])
    {
      if (num == key)
        return;
    }
    buckets[index].push_back(key);
  }

  void remove(int key)
  {
    int index = _hash(key);
    auto &bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it)
    {
      if (*it == key)
      {
        bucket.erase(it);
        return;
      }
    }
  }

  bool contains(int key)
  {
    int index = _hash(key);
    for (int num : buckets[index])
    {
      if (num == key)
        return true;
    }
    return false;
  }
};

int main()
{
  MyHashSet hashSet;
  hashSet.add(1);
  hashSet.add(2);
  cout << hashSet.contains(1) << endl; // true
  cout << hashSet.contains(3) << endl; // false
  hashSet.add(2);
  hashSet.remove(2);
  cout << hashSet.contains(2) << endl; // false
  return 0;
}
