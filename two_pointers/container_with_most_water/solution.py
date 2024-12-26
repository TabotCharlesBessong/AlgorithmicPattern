
def container_with_most_water(y_axis):
  max_area = 0
  left = 0
  right = len(y_axis) - 1
  
  while left < right:
    width = right - left
    height = min(y_axis[left], y_axis[right])
    area = width * height
    max_area = max(max_area, area)
    
    if y_axis[left] < y_axis[right]:
      left += 1
    else:
      right -= 1
  return max_area

if __name__ == '__main__':
  print(container_with_most_water([1,8,6,2,5,4,8,3,7]))