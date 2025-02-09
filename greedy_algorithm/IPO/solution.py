import heapq

def findMaximizedCapital(k,w,profits,capital):
  projects = sorted(zip(capital,profits)) # sort by capital requirements
  max_heap = []
  i = 0
  n = len(profits)
  
  for _ in range(k):
    # adding all affortable projects to the heap
    while i < n and projects[i][0] <= w:
      heapq.heappush(max_heap, -projects[i][1]) # negate the profit for max heap
      i += 1
      
    if not max_heap: # no more affortable projects
      break
    
    w += -heapq.heappop(max_heap) # extract most profitable projects
  return w

# example usage:
print(findMaximizedCapital(2, 0, [1,2,3], [0,1,1]))  # Expected: 4
print(findMaximizedCapital(3, 0, [1,2,3], [0,1,2]))  # Expected: 6