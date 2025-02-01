def minimumBoxes(apple,capacity):
  total_apples = sum(apple)
  capacity.sort(reverse=True)
  boxes_used = 0
  
  for cap in capacity:
    total_apples -= cap
    boxes_used += 1
    if total_apples <= 0:
      return boxes_used
    
# example usage

print(minimumBoxes([1, 4, 5, 7], [3, 4, 8, 10]))  # Output: 2
print(minimumBoxes([4, 5, 6], [10, 15, 20]))  # Output: 1
print(minimumBoxes([7, 4, 9, 14], [3, 6, 12, 15]))  # Output: 4