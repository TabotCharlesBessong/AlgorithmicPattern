from typing import List

class Solution:
    def minCostToEqualizeArray(self, nums: List[int], cost1: int, cost2: int) -> int:
        n, mx, mod = len(nums), max(nums), 10**9+7
        maxGap, ttlGap = mx-min(nums), mx*n-sum(nums)
        
        if cost1*2 <= cost2:
            return ttlGap*cost1 % mod
        
        if maxGap*2 <= ttlGap:
            res = ttlGap // 2 * cost2
            if ttlGap % 2 == 1:
                if n % 2 == 1:
                    res += min(cost1, cost2 * (n+1) // 2)
                else:
                    res += cost1
            return res % mod
        
        res = cost2 * (ttlGap - maxGap)
        maxGap -= ttlGap - maxGap

        if maxGap >= n-1:
            if cost2 * (n-1) >= cost1 * (n-2):
                res += maxGap // (n-1) * (n-1) * cost1
                maxGap %= n-1
            else:
                res += maxGap // (n-2) * (n-1) * cost2
                maxGap %= n-2

        if maxGap:
            op2 = (n+maxGap) // 2 * cost2
            if (n+maxGap) % 2 == 1:
                if n % 2 == 1:
                    op2 += min(cost1, cost2 * (n+1) // 2)
                else:
                    op2 += cost1

            res += min(op2, maxGap * cost1)

        return res % mod

# ✅ Example Test Cases
sol = Solution()
print(sol.minCostToEqualizeArray([1, 1000000], 1000000, 1000000)) # Expected: 998993007
print(sol.minCostToEqualizeArray([10, 20, 30], 2, 3)) # Expected: 10
print(sol.minCostToEqualizeArray([4, 8, 15, 16, 23, 42], 5, 7)) # Expected: 50
