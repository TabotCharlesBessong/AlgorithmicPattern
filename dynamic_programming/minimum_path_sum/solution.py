def minPathSum(grid: list[list[int]]) -> int:
    m, n = len(grid), len(grid[0])
    
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                continue  # Top-left corner
            elif i == 0:
                grid[i][j] += grid[i][j - 1]  # First row
            elif j == 0:
                grid[i][j] += grid[i - 1][j]  # First column
            else:
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
    
    return grid[m - 1][n - 1]

# Example usage
print(minPathSum([[1,3,1],[1,5,1],[4,2,1]])) # 7
print(minPathSum([[1,2,3],[4,5,6]])) # 12
