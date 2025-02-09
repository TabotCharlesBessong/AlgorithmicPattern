#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
  int totalApples = accumulate(apple.begin(), apple.end(), 0);
  sort(capacity.rbegin(), capacity.rend()); // Sort in descending order
  int boxesUsed = 0;

  for (int cap : capacity)
  {
    totalApples -= cap;
    boxesUsed++;
    if (totalApples <= 0)
      return boxesUsed;
  }

  return boxesUsed;
};

int main()
{
  vector<int> apple = {1, 3, 2};
  vector<int> capacity = {4, 3, 1, 5, 2};
  cout << minimumBoxes(apple, capacity) << endl; // Output: 2
  return 0;
}
