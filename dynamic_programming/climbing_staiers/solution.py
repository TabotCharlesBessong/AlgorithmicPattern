def climbStairs(n):
  if n <= 1:
    return 1
  
  dp = [1,1]
  for i in range(2, n+1):
    dp.append(dp[i-1] + dp[i-2])
    
  return dp[n]

# example usage

print(climbStairs(3)) # Output: 3
print(climbStairs(4)) # Output: 5
print(climbStairs(5)) # Output: 8

print(climbStairs(10)) # Output: 89