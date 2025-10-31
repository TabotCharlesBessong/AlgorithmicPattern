#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestSub = 1;

    for (int num : numSet)
    {
      if (numSet.find(num - 1) != numSet.end())
        continue;

      int currentNum = num;
      int currentSub = 1;

      while (numSet.find(currentNum + 1) != numSet.end())
      {
        currentNum++;
        currentSub++;
      }

      longestSub = max(longestSub, currentSub);
    }

    return longestSub;
  }
};
