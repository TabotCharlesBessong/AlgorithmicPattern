# Sliding Window Maximum
## Deque-Based Algorithm Guide

---

## 📋 Problem Statement

**Objective:** Compute the maximum value of every contiguous subarray (window) of length `k` in an array `nums` with **O(n)** time complexity.

---

## 💡 Core Concept

Maintain a **double-ended queue (deque)** of indices where the corresponding array values are in **strictly decreasing order**.

### Key Properties

- **Front of deque** → Index of the maximum element in the current window
- **Monotonic decreasing** → Values at indices in the deque decrease from front to back
- **Efficient updates** → Each element is processed at most twice (once in, once out)

### Operations Per Step

1. **Remove expired indices** — Pop front if index falls outside the current window
2. **Maintain monotonicity** — Pop back all indices with smaller values than incoming element
3. **Add current index** — Push current index to the back
4. **Record maximum** — Once window is full (`i ≥ k-1`), append `nums[deque[0]]` to result

---

## 🔧 Algorithm Pseudocode

```python
deque = empty deque of indices
result = []

for i from 0 to n-1:
    # Step 1: Remove out-of-window indices
    while deque not empty and deque[0] < i - k + 1:
        deque.pop_front()
    
    # Step 2: Maintain decreasing order in deque
    while deque not empty and nums[deque.back()] < nums[i]:
        deque.pop_back()
    
    # Step 3: Add current index
    deque.push_back(i)
    
    # Step 4: Record max for full windows
    if i >= k - 1:
        result.append(nums[deque[0]])

return result
```

---

## 📊 Example Walkthrough

### Example 1: Standard Case

**Input:** `nums = [1, 3, -1, -3, 5, 3, 6, 7]`, `k = 3`  
**Expected Output:** `[3, 3, 5, 5, 6, 7]`

| Step | i | Value | Deque (indices) | Deque (values) | Window Range | Action | Output |
|:----:|:-:|:-----:|:---------------:|:--------------:|:------------:|:-------|:------:|
| 1 | 0 | 1 | `[0]` | `[1]` | — | Push index 0 | — |
| 2 | 1 | 3 | `[1]` | `[3]` | — | Pop 0 (1 < 3), push 1 | — |
| 3 | 2 | -1 | `[1, 2]` | `[3, -1]` | [0..2] | Push 2 (keeps order) | **3** |
| 4 | 3 | -3 | `[1, 2, 3]` | `[3, -1, -3]` | [1..3] | Push 3 | **3** |
| 5 | 4 | 5 | `[4]` | `[5]` | [2..4] | Pop front 1, pop back 2,3; push 4 | **5** |
| 6 | 5 | 3 | `[4, 5]` | `[5, 3]` | [3..5] | Push 5 (5 > 3) | **5** |
| 7 | 6 | 6 | `[6]` | `[6]` | [4..6] | Pop back 4,5; push 6 | **6** |
| 8 | 7 | 7 | `[7]` | `[7]` | [5..7] | Pop back 6; push 7 | **7** |

**Result:** `[3, 3, 5, 5, 6, 7]` ✓

#### Key Observations

- **Step 5:** Value `5` dominates all previous elements → clears deque
- **Deque front:** Always points to the index of the current window's maximum
- **Monotonicity:** Smaller values are removed because they cannot be future maximums while a larger value exists

---

### Example 2: Peak in Middle

**Input:** `nums = [4, 2, 12, 3, 8, 7]`, `k = 3`  
**Expected Output:** `[12, 12, 12, 8]`

| Step | i | Value | Deque (indices) | Deque (values) | Window Range | Action | Output |
|:----:|:-:|:-----:|:---------------:|:--------------:|:------------:|:-------|:------:|
| 1 | 0 | 4 | `[0]` | `[4]` | — | Push 0 | — |
| 2 | 1 | 2 | `[0, 1]` | `[4, 2]` | — | Push 1 | — |
| 3 | 2 | 12 | `[2]` | `[12]` | [0..2] | Pop back 0,1; push 2 | **12** |
| 4 | 3 | 3 | `[2, 3]` | `[12, 3]` | [1..3] | Push 3 | **12** |
| 5 | 4 | 8 | `[2, 4]` | `[12, 8]` | [2..4] | Pop back 3; push 4 | **12** |
| 6 | 5 | 7 | `[4, 5]` | `[8, 7]` | [3..5] | Pop front 2; push 5 | **8** |

**Result:** `[12, 12, 12, 8]` ✓

#### Key Observations

- **Step 3:** The peak value `12` eliminates all previous candidates
- **Step 6:** Index `2` expires from the window → new maximum becomes `8`

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- Each element is pushed exactly once
- Each element is popped at most once
- Total operations: 2n → O(n)

### Space Complexity: **O(k)**
- Deque stores at most `k` indices
- In worst case (strictly increasing sequence), deque contains all `k` window elements

---

## ⚠️ Common Pitfalls

### 1. **Storing Values Instead of Indices**
❌ **Wrong:** `deque = [3, -1, -3]`  
✓ **Correct:** `deque = [1, 2, 3]` (indices)

**Reason:** Need indices to determine if elements are still within the window

### 2. **Off-by-One Errors**
Window starting index is `i - k + 1`, not `i - k`

### 3. **Recording Output Too Early**
Only append to result when `i >= k - 1` (first full window)

### 4. **Incorrect Comparison Direction**
Pop back when `nums[deque.back()] < nums[i]` (strictly less than)

### 5. **Not Handling Empty Deque**
Always check `deque not empty` before accessing elements

---

## 🎯 Why This Works

### Invariant Maintained
At any point, the deque contains indices `i₁ < i₂ < ... < iₘ` where:
- `nums[i₁] > nums[i₂] > ... > nums[iₘ]` (strictly decreasing values)
- All indices are within the current window

### Why Remove Smaller Elements?
If `nums[j] < nums[i]` and `j < i`, then `nums[j]` can **never** be the maximum of any future window that contains both elements.

### Why Store Indices?
To efficiently check if elements have expired from the window by comparing indices to `i - k + 1`.

---

## 🚀 Implementation Tips

```python
from collections import deque

def maxSlidingWindow(nums, k):
    if not nums or k == 0:
        return []
    
    dq = deque()
    result = []
    
    for i in range(len(nums)):
        # Remove indices outside window
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Remove indices with smaller values
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        
        dq.append(i)
        
        # Add to result when window is full
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result
```

---

## 📚 Related Problems

- **Sliding Window Minimum** (same approach, reverse comparison)
- **Longest Substring Without Repeating Characters** (different window technique)
- **Minimum Window Substring** (two-pointer approach)

---

## 📖 Further Resources

- LeetCode Problem: #239 - Sliding Window Maximum
- Time Complexity Analysis: Amortized O(n) proof
- Visual Animations: Available upon request

---

**Last Updated:** November 2025  
**Algorithm Classification:** Array, Queue, Sliding Window, Monotonic Data Structure