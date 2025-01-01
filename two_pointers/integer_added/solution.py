def find_minimum_x(nums1,nums2):
  nums1.sort()
  nums2.sort()
  min_x = float('inf')
  for i in range(3):
    x = nums2[0] - nums1[i]
    if is_valid_x(nums1,nums2,x):
      min_x = min(min_x, x)
    
  return min_x

def is_valid_x(nums1,nums2,x):
  removed_count = 0
  j = 0
  for i in range(len(nums1)):
    if j < len(nums2) and nums1[i] + x == nums2[j]:
      j += 1
    else:
      removed_count += 1
    if removed_count > 2:
      return False
    
  return True

print(find_minimum_x([4, 20, 16, 12, 8], [14, 18, 10])); # Output: -2
print(find_minimum_x([3, 5, 5, 3], [7, 7])); # Output: 2