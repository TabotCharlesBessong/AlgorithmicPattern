#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  if (nums.empty())
    return 0;

  int writeIndex = 1;
  for (int readIndex = 1; readIndex < nums.size(); readIndex++)
  {
    if (nums[readIndex] != nums[readIndex - 1])
    {
      nums[writeIndex] = nums[readIndex];
      writeIndex++;
    }
  }
  return writeIndex;
}

int main()
{
  vector<int> nums = {1, 1, 2, 3, 3};
  int length = removeDuplicates(nums);
  cout << "Unique elements: ";
  for (int i = 0; i < length; i++)
    cout << nums[i] << " ";
  cout << "\nCount: " << length << endl;
}
