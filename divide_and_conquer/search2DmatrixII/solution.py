def searchMatrix(matrix, target):
  def helper(rowStart, rowEnd, colStart, colEnd):
    if rowStart > rowEnd or colStart > colEnd:
      return False

    midRow, midCol = (rowStart + rowEnd) // 2, (colStart + colEnd) // 2
    midValue = matrix[midRow][midCol]

    if midValue == target:
      return True
    elif midValue > target:
      return (
        helper(rowStart, midRow - 1, colStart, midCol - 1) or
        helper(rowStart, midRow - 1, midCol, colEnd) or
        helper(midRow, rowEnd, colStart, midCol - 1)
        )
    else:
      return (
        helper(midRow + 1, rowEnd, midCol + 1, colEnd) or
        helper(rowStart, midRow, midCol + 1, colEnd) or
        helper(midRow + 1, rowEnd, colStart, midCol)
      )

  if not matrix or not matrix[0]:
    return False
  return helper(0, len(matrix) - 1, 0, len(matrix[0]) - 1)

def searchMatrix1(matrix: list[list[int]],target) -> bool:
  rows = len(matrix)
  cols = len(matrix[0])
  
  row, col = 0, cols - 1
  
  while row < rows and col >= 0:
    if matrix[row][col] == target:
      return True
    elif matrix[row][col] < target:
      row += 1
    else:
      col -= 1


print(searchMatrix1([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5))