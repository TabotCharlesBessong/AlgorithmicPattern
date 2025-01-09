def productExceptSelf(nums):
  n = len(nums)
  answer = [1] * n
  
  # Compute prefix products
  prefix = 1
  for i in range(n):
    answer[i] = prefix
    prefix *= nums[i]
  
  # Compute suffix products and multiply with prefix
  suffix = 1
  for i in range(n - 1, -1, -1):
    answer[i] *= suffix
    suffix *= nums[i]
  
  return answer

# Example usage
nums = [1, 2, 3, 4]
print(productExceptSelf(nums))  # Output: [24, 12, 8, 6]
