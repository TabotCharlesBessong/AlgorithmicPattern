function maxSlidingWindow(nums, k) {
  if (!nums.length || k <= 0) return [];

  const deque = [];
  const result = [];

  for (let i = 0; i < nums.length; i++) {
    // Remove indices out of window
    while (deque.length && deque[0] < i - k + 1) {
      deque.shift();
    }

    // Remove smaller numbers from deque
    while (deque.length && nums[deque[deque.length - 1]] < nums[i]) {
      deque.pop();
    }

    deque.push(i);

    // Record max in current window
    if (i >= k - 1) {
      result.push(nums[deque[0]]);
    }
  }

  return result;
}

// Example usage:
console.log(maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3)); // Output: [3,3,5,5,6,7]
