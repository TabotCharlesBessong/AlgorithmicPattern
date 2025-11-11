#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int containerWithMostWater(vector<int> &y_axis)
{
  int maxArea = 0;
  int left = 0;
  int right = y_axis.size() - 1;

  while (left < right)
  {
    int width = right - left;
    int height = min(y_axis[left], y_axis[right]);
    int area = width * height;
    maxArea = max(maxArea, area);

    if (y_axis[left] < y_axis[right])
      left++;
    else
      right--;
  }
  return maxArea;
}

int main()
{
  vector<int> y_axis = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << containerWithMostWater(y_axis) << endl;
  return 0;
}
