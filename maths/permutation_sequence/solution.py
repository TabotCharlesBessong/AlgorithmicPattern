def getPermutation(n, k):
    nums = list(range(1, n + 1))
    fact = 1
    for i in range(1, n + 1):
        fact *= i

    k -= 1  # Convert to zero-based index
    result = []
    for i in range(n):
        fact //= (n - i)
        index = k // fact
        result.append(str(nums[index]))
        nums.pop(index)
        k %= fact

    return "".join(result)

# Example
print(getPermutation(4, 9))  # Output: "2314"
