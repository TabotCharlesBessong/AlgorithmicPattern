from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs):
        if not strs:
            return []

        ans = defaultdict(list)

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            key = tuple(count)
            ans[key].append(s)

        return list(ans.values())


# Example usage
solution = Solution()
input_data = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(solution.groupAnagrams(input_data))
# Output: [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
