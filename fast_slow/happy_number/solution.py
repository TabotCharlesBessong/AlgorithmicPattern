def isHappy(n: int) -> bool:
    # Helper function to calculate the next number
    def get_next_number(num: int) -> int:
        total = 0
        while num > 0:
            digit = num % 10
            total += digit ** 2
            num //= 10
        return total

    slow, fast = n, get_next_number(n)

    while fast != 1 and slow != fast:
        slow = get_next_number(slow)
        fast = get_next_number(get_next_number(fast))

    return fast == 1

# Example usage
print(isHappy(28)) # Output: True
