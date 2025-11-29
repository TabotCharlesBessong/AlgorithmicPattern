#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int first = findBound(nums, target, true);
    if (first == -1)
      return {-1, -1};
    int last = findBound(nums, target, false);
    return {first, last};
  }

private:
  int findBound(vector<int> &nums, int target, bool isFirst)
  {
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
      int mid = (start + end) / 2;

      if (nums[mid] == target)
      {
        if (isFirst)
        {
          if (mid == start || nums[mid - 1] != target)
            return mid;
          end = mid - 1;
        }
        else
        {
          if (mid == end || nums[mid + 1] != target)
            return mid;
          start = mid + 1;
        }
      }
      else if (nums[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }

    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  vector<int> res = sol.searchRange(nums, 8);
  cout << "[" << res[0] << ", " << res[1] << "]" << endl; // [3, 4]
}
