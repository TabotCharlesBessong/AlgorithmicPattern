"""
Algorithmic Pattern: Backtracking
Problem: Generate all permutations of a string

Description:
Given a string, generate all possible permutations of its characters using 
the backtracking algorithmic pattern.

Example:
Input: "abc"
Output: ["abc", "acb", "bac", "bca", "cab", "cba"]
"""

def string_permutations(s: str) -> list[str]:
    """
    Generate all permutations of a given string using backtracking.
    
    Args:
        s (str): Input string.
        
    Returns:
        list[str]: All possible permutations of the input string.
    """
    result = []
    used = [False] * len(s)
    chars = list(s)

    def backtrack(current_perm):
        if len(current_perm) == len(chars):
            result.append(''.join(current_perm))
            return
        
        for i in range(len(chars)):
            if used[i]:
                continue
            used[i] = True
            current_perm.append(chars[i])
            backtrack(current_perm)
            current_perm.pop()
            used[i] = False

    backtrack([])
    return result


if __name__ == "__main__":
    test_str = "abc"
    print(f"Permutations of '{test_str}':")
    for p in string_permutations(test_str):
        print(p)
