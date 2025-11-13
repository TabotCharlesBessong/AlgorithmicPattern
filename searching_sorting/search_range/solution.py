class Solution:
    def searchRange(self, nums, target):
        first = self.findBound(nums, target, True)
        if first == -1:
            return [-1, -1]
        last = self.findBound(nums, target, False)
        return [first, last]

    def findBound(self, nums, target, isFirst):
        start, end = 0, len(nums) - 1

        while start <= end:
            mid = (start + end) // 2

            if nums[mid] == target:
                if isFirst:
                    if mid == start or nums[mid - 1] != target:
                        return mid
                    end = mid - 1
                else:
                    if mid == end or nums[mid + 1] != target:
                        return mid
                    start = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1

        return -1


if __name__ == "__main__":
    print(Solution().searchRange([5, 7, 7, 8, 8, 10], 8))  # Output: [3, 4]
