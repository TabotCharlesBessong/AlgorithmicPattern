#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    unordered_set<int> seen;

    for (int i = 0; i < nums.size(); ++i)
    {
      if (seen.count(nums[i]))
        return true;

      seen.insert(nums[i]);
      if (seen.size() > k)
      {
        seen.erase(nums[i - k]);
      }
    }

    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 1, 4, 5};
  int k = 3;
  bool result = sol.containsNearbyDuplicate(nums, k);
  cout << (result ? "true" : "false") << endl; // Output: true
  return 0;
}
