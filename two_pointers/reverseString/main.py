def reverseStr(s: str, k: int) -> str:
    s = list(s)  # Convert string to a list for in-place modification
    n = len(s)
    
    for i in range(0, n, 2 * k):  # Iterate in chunks of 2k
        left = i  # Start of the segment to reverse
        right = min(i + k - 1, n - 1)  # End of the segment to reverse
        
        # Reverse the characters using two pointers
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
    
    return ''.join(s)  # Convert list back to a string

# Example Usage
s = "abcdefg"
k = 5
print("Original string:", s)
print("Transformed string:", reverseStr(s, k))
