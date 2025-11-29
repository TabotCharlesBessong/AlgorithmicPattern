
def searchMatrix(matrix, target):
  if not matrix or not matrix[0]:
    return False

  m = len(matrix)
  n = len(matrix[0])

  left = 0
  right = m * n - 1

  while left <= right:
    mid = (left + right) // 2
    midValue = matrix[mid // n][mid % n]

    if midValue == target:
      return True
    elif midValue < target:
      left = mid + 1
    else:
      right = mid - 1

  return False