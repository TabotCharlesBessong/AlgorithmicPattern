import heapq
from collections import Counter

def topKFrequent(nums, k):
  if k == len(nums):
    return nums
  
  count = Counter(nums)
  heap = []

  for num, freq in count.items():
    heapq.heappush(heap, (freq, num))
    if len(heap) > k:
      heapq.heappop(heap)
  
  return [num for (freq, num) in heap]

# Example usage
print(topKFrequent([1,1,1,2,2,3], 2))  # Output: [2, 1]