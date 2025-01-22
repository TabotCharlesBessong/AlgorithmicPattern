def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    prev1, prev2 = 0, 1
    for _ in range(2, n + 1):
        current = prev1 + prev2
        prev1, prev2 = prev2, current
    return prev2

# Example Usage
print(fib(10))  # Output: 55
