def length_of_longest_substring(s):
  if not s:
    return 0
  
  if len(s) == 1:
    return 1
  
  left = 0
  right = 0
  ans = 0
  seen = set()

  while right < len(s):
    c = s[right]
    while c in seen:
      seen.remove(s[left])
      left += 1
    seen.add(c)
    ans = max(ans, right - left + 1)
    right += 1

  return ans