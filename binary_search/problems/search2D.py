def searchMatrix(matrix, target):
  m, n = len(matrix), len(matrix[0])
  left, right = 0, m * n - 1

  while left <= right:
    mid = left + (right - left) // 2
    row, col = divmod(mid, n)
    mid_value = matrix[row][col]

    if mid_value == target:
      return True
    elif mid_value < target:
      left = mid + 1
    else:
      right = mid - 1

  return False

# Example Usage
matrix = [
  [1, 3, 5],
  [7, 10, 11],
  [12, 16, 20]
]
print(searchMatrix(matrix, 10))  # Output: True
