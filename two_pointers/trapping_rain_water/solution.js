function trap(height) {
  if (height.length === 0) return 0;

  let left = 0;
  let right = height.length - 1;
  let total = 0;
  let leftMax = height[left];
  let rightMax = height[right];

  while (left < right) {
    if (height[left] < height[right]) {
      leftMax = Math.max(leftMax, height[left]);
      if (leftMax - height[left] > 0) {
        total += leftMax - height[left];
      }
      left++;
    } else {
      rightMax = Math.max(rightMax, height[right]);
      if (rightMax - height[right] > 0) {
        total += rightMax - height[right];
      }
      right--;
    }
  }

  return total;
}

console.log(trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])); // Output: 6
