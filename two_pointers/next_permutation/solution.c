
#include <stdio.h>

void swapNums(int* nums, int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void reverse(int* nums, int left, int right)
{
  while (left < right)
  {
    swapNums(nums, left, right);
    left++;
    right--;
  }
}

void nextPermutation(int* nums, int numsSize)
{
  int n = numsSize;
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