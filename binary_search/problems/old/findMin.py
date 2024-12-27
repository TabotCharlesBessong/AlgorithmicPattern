def find_min(nums):
    min_val = nums[0]
    for num in nums:
        if num < min_val:
            min_val = num
    return min_val


print(find_min([2,2,2,0,1]))