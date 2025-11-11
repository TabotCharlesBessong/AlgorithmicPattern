#include <stdio.h>

int removeDuplicates(int nums[], int size)
{
  if (size == 0)
    return 0;

  int writeIndex = 1;

  for (int readIndex = 1; readIndex < size; readIndex++)
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
  int nums[] = {1, 1, 2, 3, 3};
  int size = sizeof(nums) / sizeof(nums[0]);
  int length = removeDuplicates(nums, size);

  printf("Unique elements: ");
  for (int i = 0; i < length; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\nCount: %d\n", length);

  return 0;
}
