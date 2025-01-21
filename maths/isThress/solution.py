import math

class Solution:
    def isThree(self, n: int) -> bool:
        k = int(math.sqrt(n))
        if k * k != n:
            return False  # Check if n is a perfect square
        
        for i in range(2, int(math.sqrt(k)) + 1):
            if k % i == 0:
                return False  # Check if k is prime
        
        return k > 1  # Ensure k is greater than 1

# Example usage
sol = Solution()
print(sol.isThree(9))   # Output: True
print(sol.isThree(16))  # Output: False
