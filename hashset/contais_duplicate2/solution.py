class Solution:
    def containsNearbyDuplicate(self, nums, k):
        seen = set()

        for i, num in enumerate(nums):
            if num in seen:
                return True
            seen.add(num)

            if len(seen) > k:
                seen.remove(nums[i - k])

        return False


# Example usage
if __name__ == "__main__":
    nums = [1, 2, 3, 1, 4, 5]
    k = 3
    sol = Solution()
    result = sol.containsNearbyDuplicate(nums, k)
    print(result)  # Output: True
