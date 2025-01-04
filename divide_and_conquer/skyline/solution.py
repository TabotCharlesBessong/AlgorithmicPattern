from typing import List

def getSkyline(buildings: List[List[int]]) -> List[List[int]]:
  def merge(left,right):
    result = []
    h1 = h2 = 0
    i = j = 0
    
    while i < len(left) and j < len(right):
      if left[i][0] < right[j][0]:
        x, h1 = left[i]
        i += 1
      elif left[i][0] > right[j][0]:
        x, h2 = right[j]
        j += 1
      else:
        x, h1 = left[i]
        h2 = max(h1, right[j][1])
        i += 1
        j += 1
      
      max_height = max(h1, h2)
      if not result or result[-1][1] != max_height:
        result.append([x,max_height])
        
    result.extend(left[i:])
    result.extend(right[j:])
    return result
  
  def divide_and_conquer(start,end):
    if start == end:
      l, r, h = buildings[start]
      return [[l, h], [r, 0]]
    
    mid = (start + end) // 2
    left_skyline = divide_and_conquer(start, mid)
    right_skyline = divide_and_conquer(mid + 1, end)
    return merge(left_skyline, right_skyline)
  
  return divide_and_conquer(0, len(buildings) - 1)


print(getSkyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))