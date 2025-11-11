def next_permutation(nums):
    n = len(nums)
    i = n - 2

    # Step 1: Find first decreasing element from the end
    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1

    # Step 2: If found, find next greater element and swap
    if i >= 0:
        j = n - 1
        while j >= 0 and nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]

    # Step 3: Reverse the suffix
    nums[i + 1:] = reversed(nums[i + 1:])


# Example
if __name__ == "__main__":
    arr = [1, 2, 3]
    next_permutation(arr)
    print("Next permutation:", arr)
