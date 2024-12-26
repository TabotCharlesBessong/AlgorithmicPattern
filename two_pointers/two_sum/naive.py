def twoSum(nums,target):
  for i in range(len(nums)):
    for j in range(i+1,len(nums)):
      if nums[i] + nums[j] == target:
        return [i+1,j+1]
      
      
if __name__ == '__main__':
  print(twoSum([2,7,11,15],18))