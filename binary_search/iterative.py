def binary_search(nums,target):
  start = 0
  end = len(nums) - 1
  
  while start <= end:
    mid = (start + end) // 2
    
    if nums[mid] == target:
      return mid
    elif nums[mid] < target:
      start = mid + 1
    else:
      end = mid - 1
      
  return -1


if __name__ == '__main__':
  print(binary_search([2, 7, 11, 15], 11))  # Expected output: 2