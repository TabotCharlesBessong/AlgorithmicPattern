def addDigits(num):
    if num == 0:
        return 0
    return 1 + (num - 1) % 9

# Example
print(addDigits(38))  # Output: 2
