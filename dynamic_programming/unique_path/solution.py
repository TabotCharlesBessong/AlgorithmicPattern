def uniquePaths(m: int, n: int) -> int:
    total_steps = m + n - 2
    choose_steps = min(m - 1, n - 1)
    
    result = 1
    for i in range(1, choose_steps + 1):
        result *= total_steps
        result //= i  # Integer division to avoid floating-point inaccuracies
        total_steps -= 1
    return result

# Test Cases
print(uniquePaths(3, 7))  # Output: 28
print(uniquePaths(3, 2))  # Output: 3
print(uniquePaths(10, 10))  # Output: 48620
