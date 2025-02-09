def maxChildrenWithEightDollars(n, m):
    if n < m:
        return -1  # Not enough money to give each child at least $1
    
    remainingMoney = n - m  # Money left after giving each child $1
    count = min(remainingMoney // 7, m)  # Max children getting exactly $8

    remainingMoney -= count * 7
    m -= count

    if (m == 0 and remainingMoney > 0) or (m == 1 and remainingMoney == 3):
        count -= 1

    return count

# Example Test Cases
print(maxChildrenWithEightDollars(20, 3))  # Output: 1
print(maxChildrenWithEightDollars(16, 2))  # Output: 2
print(maxChildrenWithEightDollars(2, 2))   # Output: 0
