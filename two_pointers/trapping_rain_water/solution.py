
def trap(height):
  if not height:
    return 0
  
  left, right = 0, len(height) - 1
  left_max, right_max = height[left], height[right]
  total = 0
  
  while left < right:
    if height[left] < height[right]:
      left_max = max(left_max, height[left])
      if left_max - height[left] > 0:
        total += left_max - height[left]
      left += 1
    else:
      right_max = max(right_max, height[right])
      if right_max - height[right] > 0:
        total += right_max - height[right]
      right -= 1
  return total

# Example usage:
# height = [0,1,0,2,1,0,1,3,2,1,2,1]

if __name__ == "__main__":
  print(trap([0,1,0,2,1,0,1,3,2,1,2,1]))  # Output: 6