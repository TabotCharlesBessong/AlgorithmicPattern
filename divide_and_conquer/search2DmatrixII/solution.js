var searchMatrix = function (matrix, target) {
  const rows = matrix.length;
  const cols = matrix[0].length;

  let row = 0; // Start at the first row
  let col = cols - 1; // Start at the last column

  while (row < rows && col >= 0) {
    if (matrix[row][col] === target) {
      return true; // Found the target
    } else if (matrix[row][col] > target) {
      col--; // Eliminate the current column
    } else {
      row++; // Eliminate the current row
    }
  }

  return false; // Target not found
};

console.log(
  searchMatrix(
    [
      [1, 4, 7, 11, 15],
      [2, 5, 8, 12, 19],
      [3, 6, 9, 16, 22],
      [10, 13, 14, 17, 24],
      [18, 21, 23, 26, 30],
    ],
    (target = 5)
  )
);
