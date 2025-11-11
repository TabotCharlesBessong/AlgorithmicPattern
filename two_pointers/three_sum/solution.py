def threeSum(nums):
    nums.sort()
    result = []

    for i in range(len(nums)):
        if nums[i] > 0:
            break
        if i == 0 or nums[i] != nums[i - 1]:
            left, right = i + 1, len(nums) - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                if s < 0:
                    left += 1
                elif s > 0:
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
    return result


# ✅ Example usage
if __name__ == "__main__":
    print(threeSum([-1, 0, 1, 2, -1, -4]))
    # Output: [[-1, -1, 2], [-1, 0, 1]]
