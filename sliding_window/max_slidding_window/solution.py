from collections import deque

def max_sliding_window(nums, k):
  if not nums or k <= 0:
    return []

  dq = deque()
  result = []

  for i in range(len(nums)):
    # Remove indices out of the current window
    while dq and dq[0] < i - k + 1:
      dq.popleft()

    # Remove smaller values from the deque
    while dq and nums[dq[-1]] < nums[i]:
      dq.pop()

    dq.append(i)

    # Add the maximum for the current window
    if i >= k - 1:
      result.append(nums[dq[0]])

  return result


# Example usage:
print(max_sliding_window([1,3,-1,-3,5,3,6,7], 3))  # Output: [3,3,5,5,6,7]
