def twoSum(nums,target):
  pointer1 = 0
  pointer2 = len(nums) - 1
  
  while pointer1 < pointer2:
    sum = nums[pointer1] + nums[pointer2]
    if sum == target:
      return [pointer1+1, pointer2+1]
    elif sum < target:
      pointer1 += 1
    else:
      pointer2 -= 1
      
      
if __name__ == '__main__':
  print(twoSum([2,7,11,15],18))