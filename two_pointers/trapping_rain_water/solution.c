
#include <stdio.h>

int trap(int height[], int n){
  if (n == 0) return 0;

  int left = 0;
  int right = n - 1;
  int total = 0;
  int leftMax = height[left];
  int rightMax = height[right];

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] > leftMax) {
        leftMax = height[left];
      } else {
        total += leftMax - height[left];
      }
      left++;
    } else {
      if (height[right] > rightMax) {
        rightMax = height[right];
      } else {
        total += rightMax - height[right];
      }
      right--;
    }
  }
  return total;
}

int main()
{
  int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(height) / sizeof(height[0]);
  printf("%d\n", trap(height, n)); // Output: 6
  return 0;
}