def fib(n):
    # if n == 0:
    #     return 0
    # if n == 1:
    #     return 1

    # prev1, prev2 = 0, 1
    # for _ in range(2, n + 1):
    #     current = prev1 + prev2
    #     prev1, prev2 = prev2, current
    # return prev2
    
    if n == 0:
        return 0
    if n == 1:
        return 1

    dp = [0] * (n + 1)
    dp[0], dp[1] = 0, 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

# Example Usage
print(fib(10))  # Output: 55
