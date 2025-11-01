# LeetCode 41: First Missing Positive

## Problem Statement

Given an unsorted integer array `nums`, return the smallest missing positive integer.

You must implement an algorithm that runs in `O(n)` time and uses constant extra space.

**Example 1:**
```
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

**Example 2:**
```
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

**Example 3:**
```
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

**Constraints:**
- `1 <= nums.length <= 10⁵`
- `-2³¹ <= nums[i] <= 2³¹ - 1`

## Key Insights

The answer must be in the range `[1, n+1]` where `n` is the length of the array:
- **Why?** If all numbers from 1 to n are present, then the answer is n+1
- **Why not larger?** An array of length n can contain at most n distinct positive integers

## Approach 1: Brute Force Solution

### Algorithm
1. Start with candidate = 1
2. For each candidate, check if it exists in the array
3. If not found, return candidate
4. Otherwise, increment candidate and repeat

### Implementation Walkthrough

```python
def first_missing_positive_brute_force(nums):
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
```

### Example Walkthrough: `[3, 4, -1, 1]`

1. **candidate = 1**: Check if 1 exists → Found at index 3 → continue
2. **candidate = 2**: Check if 2 exists → Not found → **Return 2**

### Complexity Analysis
- **Time Complexity:** O(n²) - For each candidate (worst case n+1), we scan the entire array
- **Space Complexity:** O(1) - Only using a few variables

### Why Brute Force is Inefficient
- We might check many candidates unnecessarily
- Each check requires scanning the entire array
- No optimization for already processed information

## Approach 2: Optimal Solution - Index as Hash Map

### Key Insight
Use the array itself as a hash map! Since we only care about numbers 1 to n, we can:
- Use index i to represent number i+1
- Mark presence by making the value at that index negative

### Algorithm Steps

#### Step 1: Handle Special Case
If 1 is not in the array, return 1 immediately (since 1 is the smallest positive integer).

#### Step 2: Normalize the Array
Replace all numbers ≤ 0 or > n with 1. This ensures all numbers are in range [1, n].

#### Step 3: Mark Presence Using Signs
For each number x in the array:
- Mark its presence by making `nums[x-1]` negative
- Special case: if x = n, mark `nums[0]` negative (since n maps to index n-1, but we handle n separately)

#### Step 4: Find First Missing
Scan indices 1 to n-1. The first positive value indicates a missing number.

### Detailed Example Walkthrough: `[3, 4, -1, 1]`

**Initial:** `[3, 4, -1, 1]`

#### Step 1: Check if 1 exists
- Scan array: found 1 at index 3 ✓
- Continue to next step

#### Step 2: Normalize array
- Replace numbers ≤ 0 or > n (n=4)
- `nums[2] = -1` → replace with 1
- **Result:** `[3, 4, 1, 1]`

#### Step 3: Mark presence using signs
Process each number and mark presence:

**Process nums[0] = 3:**
- Number 3 should be at index 2 (3-1=2)
- Make `nums[2]` negative: `nums[2] = -|nums[2]| = -1`
- **Array:** `[3, 4, -1, 1]`

**Process nums[1] = 4:**
- Number 4 should be at index 3 (4-1=3) 
- Make `nums[3]` negative: `nums[3] = -|nums[3]| = -1`
- **Array:** `[3, 4, -1, -1]`

**Process nums[2] = -1 (abs = 1):**
- Number 1 should be at index 0 (1-1=0)
- Make `nums[0]` negative: `nums[0] = -|nums[0]| = -3`
- **Array:** `[-3, 4, -1, -1]`

**Process nums[3] = -1 (abs = 1):**
- Number 1 should be at index 0 (already negative)
- `nums[0]` remains `-3`
- **Array:** `[-3, 4, -1, -1]`

#### Step 4: Find first missing
Check indices 1 to n-1:
- `nums[1] = 4` (positive) → index 1 represents number 2 → **Missing number is 2**

### Visual Representation

```
Array indices:  [0]  [1]  [2]  [3]
Represents:      1    2    3    4
Final values:   [-3]  [4] [-1] [-1]
Signs:           -    +    -    -
Missing:              ↑
                     2 is missing!
```

### Another Example: `[1, 2, 0]`

**Initial:** `[1, 2, 0]` (n=3)

#### Step 1: Check if 1 exists ✓

#### Step 2: Normalize
- Replace `nums[2] = 0` with 1
- **Result:** `[1, 2, 1]`

#### Step 3: Mark presence
- Process 1: `nums[0] = -1` → `[-1, 2, 1]`
- Process 2: `nums[1] = -2` → `[-1, -2, 1]`  
- Process 1: `nums[0]` already negative → `[-1, -2, 1]`

#### Step 4: Find missing
- `nums[1] = -2` (negative) ✓
- `nums[2] = 1` (positive) → **Missing number is 3**

### Why This Works

1. **Range Constraint:** Answer is always in [1, n+1]
2. **Index Mapping:** Index i represents number i+1
3. **Sign as Flag:** Negative sign indicates presence
4. **Constant Space:** Uses the array itself as hash map

### Edge Cases Handled

1. **Array without 1:** Return 1 immediately
2. **All numbers present:** Return n+1
3. **Negative numbers:** Replaced with 1 in normalization
4. **Numbers > n:** Replaced with 1 in normalization
5. **Number n:** Special handling using index 0

### Complexity Analysis

- **Time Complexity:** O(n) - Four linear passes through array
- **Space Complexity:** O(1) - Only modifies input array, no extra space

### Step-by-Step Algorithm Summary

```
1. IF 1 not in array: RETURN 1
2. NORMALIZE: Replace nums[i] with 1 if nums[i] ≤ 0 or nums[i] > n
3. MARK: For each |nums[i]|, make nums[|nums[i]|-1] negative
4. FIND: Return first index i where nums[i] > 0, representing missing number i+1
```

## Comparison: Brute Force vs Optimal

| Aspect | Brute Force | Optimal |
|--------|-------------|---------|
| **Time** | O(n²) | O(n) |
| **Space** | O(1) | O(1) |
| **Approach** | Check each candidate | Index as hash map |
| **Efficiency** | Poor for large arrays | Excellent |
| **Intuition** | Simple but slow | Clever space optimization |

## Common Mistakes to Avoid

1. **Forgetting to check for 1 first** - Without 1, we can't use the marking strategy
2. **Not handling number n correctly** - Since n maps to index n-1, we use index 0 for n
3. **Forgetting absolute value** - When processing marked numbers, use `abs(nums[i])`
4. **Wrong index mapping** - Number x maps to index x-1, not x
5. **Not normalizing properly** - Numbers outside [1,n] must be replaced

## Why O(1) Space is Challenging

The constraint "constant extra space" eliminates:
- ✗ Hash sets to store seen numbers
- ✗ Boolean arrays to mark presence  
- ✗ Sorting (requires O(log n) space for most algorithms)

The optimal solution cleverly uses the input array itself as storage!