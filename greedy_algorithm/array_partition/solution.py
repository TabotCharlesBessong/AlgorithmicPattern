def arrayPairSum(nums):
    nums.sort()
    return sum(nums[i] for i in range(0, len(nums), 2))

# Example usage
print(arrayPairSum([6,2,6,5,1,2]))  # Output: 9
