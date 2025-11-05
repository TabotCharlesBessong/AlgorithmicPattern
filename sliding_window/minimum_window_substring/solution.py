
def min_window(s: str, t: str) -> str:
  if not s or not t or len(s) < len(t):
    return ""
  
  from collections import Counter
  
  dict_t = Counter(t)
  required = len(dict_t)
  sub_map = {}
  l = 0
  formed = 0
  ans = (float("inf"),0,0)
  
  for r, c in enumerate(s):
    sub_map[c] = sub_map.get(c, 0) + 1
    
    if c in dict_t and sub_map[c] == dict_t[c]:
      formed += 1
      
    while l <= r and formed == required:
      if ans[0] > r - l + 1:
        ans = (r - l + 1, l, r)
        
      char = s[l]
      sub_map[char] -= 1
      if char in dict_t and sub_map[char] < dict_t[char]:
        formed -= 1
      l += 1
      
  return "" if ans[0] == float("inf") else s[ans[1]:ans[2]+1]


print(min_window("ADOBECODEBANC", "ABC"))  # Output: "BANC"
