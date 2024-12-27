function searchMatrix(matrix, target) {
  const m = matrix.length,
    n = matrix[0].length;
  let left = 0,
    right = m * n - 1;

  while (left <= right) {
    const mid = Math.floor(left + (right - left) / 2);
    const row = Math.floor(mid / n);
    const col = mid % n;
    const midValue = matrix[row][col];

    if (midValue === target) {
      return true;
    } else if (midValue < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

// Example Usage
const matrix = [
  [1, 3, 5],
  [7, 10, 11],
  [12, 16, 20],
];
console.log(searchMatrix(matrix, 10)); // Output: true
