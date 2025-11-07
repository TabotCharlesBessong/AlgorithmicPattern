function containerWithMostWater(y_axis) {
  let maxArea = 0;
  let left = 0;
  let right = y_axis.length - 1;

  while (left < right) {
    const width = right - left;
    const height = Math.min(y_axis[left], y_axis[right]);
    const area = width * height;
    maxArea = Math.max(maxArea, area);

    if (y_axis[left] < y_axis[right]) {
      left++;
    } else {
      right--;
    }
  }
  return maxArea;
}

console.log(containerWithMostWater([1, 8, 6, 2, 5, 4, 8, 3, 7]));
