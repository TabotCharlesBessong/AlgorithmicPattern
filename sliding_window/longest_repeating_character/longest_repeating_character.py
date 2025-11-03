"""
Title: Longest Repeating Character Replacement (#108)
Pattern: Sliding Window
Description:
    Given a string s and an integer k, return the length of the longest substring 
    containing the same letter you can get after performing at most k character replacements.

Example:
    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'B' to get "AABA" or "ABBA"

Time Complexity: O(n)
Space Complexity: O(1)
"""

def longest_repeating_character_replacement(s: str, k: int) -> int:
    from collections import defaultdict

    freq = defaultdict(int)
    max_count = 0  # max frequency of a single character in the window
    left = 0
    result = 0

    for right in range(len(s)):
        freq[s[right]] += 1
        max_count = max(max_count, freq[s[right]])

        # If replacements exceed k, shrink the window
        while (right - left + 1) - max_count > k:
            freq[s[left]] -= 1
            left += 1

        result = max(result, right - left + 1)

    return result


# Example usage:
if __name__ == "__main__":
    print(longest_repeating_character_replacement("AABABBA", 1))  # Output: 4
