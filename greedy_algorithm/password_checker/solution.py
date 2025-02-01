import string
import re

def strongPasswordChecker(s):
    
    lowercase = set(string.ascii_lowercase)
    uppercase = set(string.ascii_uppercase)
    digits = set([str(elem for elem in range(10))])
    
    num_deletions = max(0,len(s) - 20)
    
    has_lowercase = any((character in lowercase for character in s))
    has_uppercase = any((character in uppercase for character in s))
    has_digits = any((character in digits for character in s))
    num_missing_types = (not has_lowercase) + (not has_uppercase) + (not has_digits)
    
    substring_lengths = count_substring_lengths(s)
    break_substrings_with_deletions(substring_lengths,num_deletions)
    num_substring_breaks = sum([length // 3 for length in substring_lengths if length >= 3])
    
    num_insertions = max(0, 6 - len(s))
    
    return num_deletions + max(num_missing_types, num_insertions, num_substring_breaks)
    
    
def count_substring_lengths(s):
    result = [1]
    last_seen_character = s[0]
    for idx in range(1,len(s)):
        if s[idx] == last_seen_character:
            result[-1] += 1
        else:
            result.append(1)
            last_seen_character = s[idx]
            
    return result
    
  
def break_substrings_with_deletions(substring_lengths,num_deletions):
    while num_deletions > 0:
        best_tuple_to_delete = min(enumerate(substring_lengths), key=lambda pair: pair[1] % 3 if pair[1] >= 3 else float("inf"))
        best_idx_to_delete = best_tuple_to_delete[0]
        substring_lengths[best_idx_to_delete] -= 1
        num_deletions -= 1  

def strong_password_checker(pw,min_lenght=6,max_lenght=20,max_repeat=2):
    pattern = re.compile(r'(.)\1{0,' + str(max_repeat) + r'}(?=\1{' + str(max_repeat) + r'})')
    changes = sorted((len(m.group(0)) for m in pattern.finditer(pw)),reverse=True)
    
    to_remove = len(pw) - max_lenght
    while changes and changes[-1] <= to_remove:
        to_remove -= changes.pop()
        
    num_changes = max(
        len(changes),
        int(not any(c.islower() for c in pw)) +
        int(not any(c.isupper() for c in pw)) +
        int(not any(c.isdigit() for c in pw)) 
    )
    
    return max(min_lenght - len(pw), num_changes + max(0,len(pw) - max_lenght))

# Example Usage
print(strongPasswordChecker("a"))        # Output: 5
print(strongPasswordChecker("aaa111"))   # Output: 2
print(strongPasswordChecker("aaaBBB111"))   # Output: 3
print(strongPasswordChecker("AAAAAAAAAAAAA12345"))   # Output: 4
print(strongPasswordChecker("aaabbbbcccccdddddd")) # Output: 5,

# ✅ Test Case
print(strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA")); # Expected: 23

# Example Usage
print(strong_password_checker("a"))        # Output: 5
print(strong_password_checker("aaa111"))   # Output: 2
print(strong_password_checker("aaaBBB111"))   # Output: 3
print(strong_password_checker("AAAAAAAAAAAAA12345"))   # Output: 4
print(strong_password_checker("aaabbbbcccccdddddd")) # Output: 5,

# ✅ Test Case
print(strong_password_checker("FFFFFFFFFFFFFFF11111111111111111111AAA")); # Expected: 23
