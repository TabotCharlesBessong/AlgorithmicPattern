# String Permutation using Sliding Window

This problem demonstrates how to find all permutations of a given string using the sliding window technique. A permutation is a rearrangement of characters in different orders.

## Problem Statement

Given a string `s`, return all possible permutations of the string.

Example:
```
Input: s = "abc"
Output: ["abc", "acb", "bac", "bca", "cab", "cba"]
```

## Solution Approach

We use a sliding window approach combined with backtracking to generate all possible permutations:

1. Initialize a window that will hold characters we've processed
2. For each position in the permutation:
   - Try placing each unused character in the current position
   - Mark the character as used
   - Recursively generate permutations for remaining positions
   - Unmark the character (backtrack)

## Time and Space Complexity

- Time Complexity: O(n!), where n is the length of the string
  - We have n choices for first character, (n-1) for second, and so on
- Space Complexity: O(n)
  - We need space to store the current permutation and visited status

## Implementation Details

The solution is implemented in both Java and Python:

### Key Components

1. **Visited Array/Set**: Tracks which characters we've used in current permutation
2. **StringBuilder/List**: Builds current permutation
3. **Backtracking**: Allows us to try different combinations

### Algorithm Steps

1. Convert input string to character array for easier manipulation
2. Initialize data structures to track:
   - Current permutation being built
   - Which characters have been used
3. Use backtracking to:
   - Place unused characters in current position
   - Recursively fill remaining positions
   - Undo choices to try different combinations
4. Add completed permutations to result list

## Usage

Check the accompanying Java and Python implementations for detailed code examples.

### Java
```java
StringPermutation sp = new StringPermutation();
List<String> result = sp.findPermutations("abc");
// result will contain ["abc", "acb", "bac", "bca", "cab", "cba"]
```

### Python
```python
sp = StringPermutation()
result = sp.find_permutations("abc")
# result will contain ["abc", "acb", "bac", "bca", "cab", "cba"]
```

## Edge Cases and Constraints

1. Empty string returns empty list
2. Single character returns list with just that character
3. Duplicate characters in input string will generate duplicate permutations unless handled specifically
4. String length should be reasonable (typically ≤ 8) due to factorial time complexity