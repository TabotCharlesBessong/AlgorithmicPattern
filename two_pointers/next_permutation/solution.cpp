#include <iostream>
#include <vector>
using namespace std;

void swapNums(vector<int> &nums, int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void reverse(vector<int> &nums, int left, int right)
{
  while (left < right)
  {
    swapNums(nums, left, right);
    left++;
    right--;
  }
}

void nextPermutation(vector<int> &nums)
{
  int n = nums.size();
  int i = n - 2;

  // Step 1: Find first decreasing element
  while (i >= 0 && nums[i] >= nums[i + 1])
  {
    i--;
  }

  // Step 2: Swap with next greater element
  if (i >= 0)
  {
    int j = n - 1;
    while (j >= 0 && nums[j] <= nums[i])
    {
      j--;
    }
    swapNums(nums, i, j);
  }

  // Step 3: Reverse the suffix
  reverse(nums, i + 1, n - 1);
}

int main()
{
  vector<int> nums = {1, 2, 3};
  nextPermutation(nums);
  cout << "Next permutation: ";
  for (int n : nums)
    cout << n << " ";
  cout << endl;
}
