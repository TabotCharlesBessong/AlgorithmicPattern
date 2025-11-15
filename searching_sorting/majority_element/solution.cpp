#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
  unordered_map<int, int> counts;

  // Count occurrences
  for (int num : nums)
  {
    counts[num]++;
  }

  // Find majority element
  int majorityKey = -1;
  int majorityCount = -1;

  for (auto &entry : counts)
  {
    if (entry.second > majorityCount)
    {
      majorityKey = entry.first;
      majorityCount = entry.second;
    }
  }

  return majorityKey;
}

int main()
{
  vector<int> nums = {3, 2, 3};
  cout << majorityElement(nums) << endl;
  nums = {2, 2, 1, 1, 1, 2, 2};
  cout << majorityElement(nums) << endl;
}
