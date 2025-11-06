#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  if (nums.empty() || k <= 0)
    return {};

  deque<int> dq;
  vector<int> result;

  for (int i = 0; i < nums.size(); i++)
  {
    // Remove indices out of current window
    while (!dq.empty() && dq.front() < i - k + 1)
      dq.pop_front();

    // Remove smaller values
    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);

    // Add current max
    if (i >= k - 1)
      result.push_back(nums[dq.front()]);
  }

  return result;
}

int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> res = maxSlidingWindow(nums, k);
  for (int n : res)
    cout << n << " ";
  return 0;
}
