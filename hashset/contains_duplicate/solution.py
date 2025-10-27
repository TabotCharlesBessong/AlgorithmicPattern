class Solution:
    def containsDuplicate(self, nums):
        seen_numbers = set()

        for num in nums:
            if num in seen_numbers:
                return True
            seen_numbers.add(num)

        return False


# Example usage
if __name__ == "__main__":
    nums = [1, 2, 3, 1]
    sol = Solution()
    result = sol.containsDuplicate(nums)
    print("Contains duplicate:", result)  # Output: True
