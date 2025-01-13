#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height){
  int left = 0, right = height.size() - 1;
  int leftMax = 0, rightMax = 0, waterTrapped = 0;

  while (left < right){
    if(height[left] < height[right]){
      if(height[left] >= leftMax){
        leftMax = height[left];
      }else{
        waterTrapped += leftMax - height[left];
      }
      left++;
    }else{
      if(height[right] >= rightMax){
        rightMax = height[right];
      }else{
        waterTrapped += rightMax - height[right];
      }
      right--;
    }
  }
  return waterTrapped;
}

int main()
{
  vector<int> height = {4, 2, 0, 3, 2, 5};
  cout << "Water Trapped: " << trap(height) << endl;
}