import heapq

def findKthLargest(nums, k):
  max_heap = [-num for num in nums]
  heapq.heapify(max_heap)  # Transform the list into a heap
  for _ in range(k - 1):
    heapq.heappop(max_heap)
  return -heapq.heappop(max_heap)

# Example usage
nums = [7, 10, 4, 3, 20, 15, 8, 6]
k = 3
print(findKthLargest(nums, k))  # Output: 10
