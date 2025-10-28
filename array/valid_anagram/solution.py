class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
      # print("one")
      return False

    char_count = [0] * 26

    for i in range(len(s)):
      char_count[ord(s[i]) - ord('a')] += 1
      char_count[ord(t[i]) - ord('a')] -= 1

    for count in char_count:
      if count != 0:
        # print("two")
        return False

    # print("three")
    return True
  