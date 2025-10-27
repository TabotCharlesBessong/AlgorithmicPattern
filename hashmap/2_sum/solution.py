class Solution:
  def twoSum(self, nums, target):
    hashmap = {}
    for i, num in enumerate(nums):
      complement = target - num
      if complement in hashmap:
        return [hashmap[complement], i]
      hashmap[num] = i
    return []
  
  
# Example usage:
if __name__ == "__main__":
  solution = Solution()
  nums = [2, 7, 11, 15]
  target = 9
  result = solution.twoSum(nums, target)
  print(f"Indices of the two numbers that add up to {target}: {result}")