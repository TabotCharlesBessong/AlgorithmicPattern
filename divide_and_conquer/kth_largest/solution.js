function findKthLargest(nums, k) {
  const maxHeap = [];
  nums.forEach((num) => maxHeap.push(num));
  maxHeap.sort((a, b) => b - a); // Simulating max heap behavior
  return maxHeap[k - 1];
}

// Example usage
const nums = [7, 10, 4, 3, 20, 15, 8, 6];
const k = 3;
console.log(findKthLargest(nums, k)); // Output: 10
