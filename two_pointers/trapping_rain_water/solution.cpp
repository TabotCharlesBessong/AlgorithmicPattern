#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height)
{
  if (height.empty())
    return 0;

  int left = 0;
  int right = height.size() - 1;
  int total = 0;
  int leftMax = height[left];
  int rightMax = height[right];

  while (left < right)
  {
    if (height[left] < height[right])
    {
      leftMax = max(leftMax, height[left]);
      if (leftMax - height[left] > 0)
      {
        total += leftMax - height[left];
      }
      left++;
    }
    else
    {
      rightMax = max(rightMax, height[right]);
      if (rightMax - height[right] > 0)
      {
        total += rightMax - height[right];
      }
      right--;
    }
  }
  return total;
}

int main()
{
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << trap(height) << endl; // Output: 6
  return 0;
}
