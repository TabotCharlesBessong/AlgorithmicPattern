def isSubsequence(s: str, t: str) -> bool:
    i, j = 0, 0
    while j < len(t):
        if i < len(s) and s[i] == t[j]:
            i += 1
        j += 1
    return i == len(s)

# Example usage
print(isSubsequence("abc", "ahbgdc"))  # true
print(isSubsequence("axc", "ahbgdc"))  # false
