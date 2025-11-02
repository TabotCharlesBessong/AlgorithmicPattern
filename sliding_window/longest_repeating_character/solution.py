def character_replacement(s: str, k: int) -> int:
  occurrence = [0] * 26
  left = 0
  ans = 0
  max_occurrence = 0

  for right in range(len(s)):
    index = ord(s[right]) - ord('A')
    occurrence[index] += 1
    max_occurrence = max(max_occurrence, occurrence[index])

    if (right - left + 1 - max_occurrence) > k:
      occurrence[ord(s[left]) - ord('A')] -= 1
      left += 1
    else:
      ans = max(ans, right - left + 1)

  return ans


# Example Usage
print(character_replacement("AABABBA", 1))  # Output: 4
