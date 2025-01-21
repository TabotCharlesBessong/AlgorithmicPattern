class Solution:
  def isUgly(self, n: int) -> bool:
    if n <= 0:
      return False
    
    for factor in [2, 3, 5]:
      while n % factor == 0:
        n //= factor
    
    return n == 1

# Example usage
sol = Solution()
print(sol.isUgly(6))   # Output: True
print(sol.isUgly(14))  # Output: False
