def check_inclusion(s1: str, s2: str) -> bool:
  if len(s1) > len(s2):
    return False

  s1_map = [0] * 26
  s2_map = [0] * 26

  for i in range(len(s1)):
    s1_map[ord(s1[i]) - ord('a')] += 1
    s2_map[ord(s2[i]) - ord('a')] += 1

  def matches(a, b):
    return a == b

  for i in range(len(s2) - len(s1)):
    if matches(s1_map, s2_map):
      return True
    s2_map[ord(s2[i + len(s1)]) - ord('a')] += 1
    s2_map[ord(s2[i]) - ord('a')] -= 1

  return matches(s1_map, s2_map)


# Example usage:
print(check_inclusion("ab", "eidbaooo"))  # True
print(check_inclusion("ab", "eidboaoo"))  # False
