"""
First Missing Positive - LeetCode 41

Brute Force Approach: Check each positive integer starting from 1
Time Complexity: O(n²)
Space Complexity: O(1)
"""

def first_missing_positive_brute_force(nums):
    """
    BRUTE FORCE SOLUTION
    
    Args:
        nums (List[int]): Array of integers
        
    Returns:
        int: First missing positive integer
        
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    candidate = 1
    
    while True:
        # Check if candidate exists in array
        found = False
        for num in nums:
            if num == candidate:
                found = True
                break
        
        # If candidate not found, it's our answer
        if not found:
            return candidate
            
        candidate += 1

def first_missing_positive(nums):
    """
    OPTIMAL SOLUTION - Index as Hash Map
    
    Args:
        nums (List[int]): Array of integers
        
    Returns:
        int: First missing positive integer
        
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(nums)
    
    # Step 1: Check if 1 exists in array
    contains_1 = False
    for num in nums:
        if num == 1:
            contains_1 = True
            break
    
    # If 1 is not present, return 1
    if not contains_1:
        return 1
    
    # Step 2: Replace numbers <= 0 or > n with 1
    for i in range(n):
        if nums[i] <= 0 or nums[i] > n:
            nums[i] = 1
    
    # Step 3: Use array indices as hash map
    # Mark presence of number x by making nums[x-1] negative
    for i in range(n):
        num = abs(nums[i])
        if num == n:
            nums[0] = -abs(nums[0])
        else:
            nums[num] = -abs(nums[num])
    
    # Step 4: Find first positive number (missing positive)
    for i in range(1, n):
        if nums[i] > 0:
            return i
    
    # Check if n is missing
    if nums[0] > 0:
        return n
    
    # All numbers 1 to n are present
    return n + 1

# Test cases
if __name__ == "__main__":
    print("=== First Missing Positive - Test Cases ===")
    
    # Test Brute Force
    print("Brute Force Results:")
    print(f"Test 1: {first_missing_positive_brute_force([1, 2, 0])}")  # Expected: 3
    print(f"Test 2: {first_missing_positive_brute_force([3, 4, -1, 1])}")  # Expected: 2
    print(f"Test 3: {first_missing_positive_brute_force([7, 8, 9, 11, 12])}")  # Expected: 1
    
    # Test Optimal
    print("\nOptimal Solution Results:")
    print(f"Test 1: {first_missing_positive([1, 2, 0])}")  # Expected: 3
    print(f"Test 2: {first_missing_positive([3, 4, -1, 1])}")  # Expected: 2
    print(f"Test 3: {first_missing_positive([7, 8, 9, 11, 12])}")  # Expected: 1
    
    # Additional Edge Cases
    print("\n=== Edge Cases ===")
    print(f"Empty array: {first_missing_positive([])}")  # Expected: 1
    print(f"Single element [1]: {first_missing_positive([1])}")  # Expected: 2
    print(f"Single element [2]: {first_missing_positive([2])}")  # Expected: 1
    print(f"All negatives: {first_missing_positive([-1, -2, -3])}")  # Expected: 1