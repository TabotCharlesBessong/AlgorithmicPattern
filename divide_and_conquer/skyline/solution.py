from typing import List
import heapq

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


def getSkyline1(buildings):
  # Step 1: Create events for start and end of buildings
  events = []
  for start, end, height in buildings:
    events.append((start, -height))  # Start event
    events.append((end, height))    # End event
  
  # Step 2: Sort events
  # Sort by x, and for the same x, sort starts (-height) before ends (height)
  events.sort(key=lambda x: (x[0], x[1]))
  
  # Step 3: Process events using a max heap
  result = []
  active_heights = [0]  # Initial ground level
  prev_max_height = 0
  
  for x, h in events:
    if h < 0:  # Start of a building
      heapq.heappush(active_heights, h)  # Add height (negative for max heap)
    else:  # End of a building
      active_heights.remove(-h)  # Remove height (convert back to negative)
      heapq.heapify(active_heights)  # Re-heapify to maintain max heap
    
    # Current max height
    curr_max_height = -active_heights[0]
    if curr_max_height != prev_max_height:
      result.append([x, curr_max_height])
      prev_max_height = curr_max_height
  
  return result


print(getSkyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))