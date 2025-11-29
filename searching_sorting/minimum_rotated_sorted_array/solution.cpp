#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int> &nums)
{
  int left = 0;
  int right = nums.size() - 1;
  int ans = nums[0];

  if (nums.size() == 1)
    return nums[0];

  while (left <= right)
  {
    if (nums[left] < nums[right])
    {
      ans = min(ans, nums[left]);
    }

    int mid = (left + right) / 2;
    ans = min(ans, nums[mid]);

    if (nums[left] <= nums[mid])
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return ans;
}

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << findMin(nums) << endl;
}
