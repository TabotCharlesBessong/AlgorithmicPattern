#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  int pointer1 = 0, pointer2 = nums.size() - 1;

  while (pointer1 < pointer2)
  {
    int sum = nums[pointer1] + nums[pointer2];
    if (sum == target)
    {
      return {pointer1 + 1, pointer2 + 1};
    }
    else if (sum < target)
    {
      pointer1++;
    }
    else
    {
      pointer2--;
    }
  }
  return {-1, -1};
}

int main()
{
  vector<int> nums = {2, 7, 11, 15};
  vector<int> res = twoSum(nums, 18);
  cout << "[" << res[0] << ", " << res[1] << "]" << endl; // [2, 3]
  return 0;
}
