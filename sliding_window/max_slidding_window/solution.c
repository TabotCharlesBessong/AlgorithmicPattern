#include <stdio.h>

void maxSlidingWindow(int *nums, int n, int k, int *result)
{
  int deque[n]; // store indices
  int front = 0, back = 0;
  int resIndex = 0;

  for (int i = 0; i < n; i++)
  {
    // Remove indices out of current window
    if (front < back && deque[front] < i - k + 1)
      front++;

    // Remove smaller values
    while (front < back && nums[deque[back - 1]] < nums[i])
      back--;

    deque[back++] = i;

    // Add result when window is ready
    if (i >= k - 1)
      result[resIndex++] = nums[deque[front]];
  }
}

int main()
{
  int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
  int n = sizeof(nums) / sizeof(nums[0]);
  int k = 3;
  int result[n - k + 1];

  maxSlidingWindow(nums, n, k, result);

  for (int i = 0; i < n - k + 1; i++)
    printf("%d ", result[i]);
  return 0;
}
