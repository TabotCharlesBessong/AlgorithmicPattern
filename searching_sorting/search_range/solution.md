Perfect 👌 — let’s go through a **detailed algorithmic walkthrough** of the `searchRange` algorithm (in your Java / multi-language equivalent).

We’ll break it down **step-by-step**, showing how the algorithm finds the **first and last positions** of a target element in a sorted array.

---

## ⚙️ Algorithm Overview

The problem:

> Given a sorted array `nums`, find the **starting and ending positions** of a given `target` value.

If the target is not found, return `[-1, -1]`.

The algorithm uses **binary search twice**:

1. First binary search → find the **first (leftmost)** occurrence.
2. Second binary search → find the **last (rightmost)** occurrence.

---

## 🧩 Step-by-Step Algorithm

Let’s recall the logic in plain pseudocode:

```
function searchRange(nums, target):
    first = findBound(nums, target, true)
    if first == -1:
        return [-1, -1]
    last = findBound(nums, target, false)
    return [first, last]

function findBound(nums, target, isFirst):
    start = 0
    end = len(nums) - 1
    while start <= end:
        mid = (start + end) // 2
        if nums[mid] == target:
            if isFirst:
                if mid == start or nums[mid-1] != target:
                    return mid
                end = mid - 1
            else:
                if mid == end or nums[mid+1] != target:
                    return mid
                start = mid + 1
        else if nums[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return -1
```

---

## 🧠 Example 1: `nums = [5, 7, 7, 8, 8, 10]`, `target = 8`

### 🔹 Step 1 — Find first occurrence (`isFirst = true`)

| Step | start | end | mid | nums[mid] | Action                                                                                           |
| ---- | ----- | --- | --- | --------- | ------------------------------------------------------------------------------------------------ |
| 1    | 0     | 5   | 2   | 7         | 7 < 8 → move right → `start = mid + 1 = 3`                                                       |
| 2    | 3     | 5   | 4   | 8         | Found 8 → check left neighbor `nums[3] = 8` → duplicate left, so move left → `end = mid - 1 = 3` |
| 3    | 3     | 3   | 3   | 8         | Found 8 → `mid == start` → ✅ return `3`                                                          |

**First index found:** `3`

---

### 🔹 Step 2 — Find last occurrence (`isFirst = false`)

| Step | start | end | mid | nums[mid] | Action                                                                   |
| ---- | ----- | --- | --- | --------- | ------------------------------------------------------------------------ |
| 1    | 0     | 5   | 2   | 7         | 7 < 8 → move right → `start = 3`                                         |
| 2    | 3     | 5   | 4   | 8         | Found 8 → check right neighbor `nums[5] = 10` (not equal) → ✅ return `4` |

**Last index found:** `4`

---

✅ **Final Output:** `[3, 4]`

The range of 8’s in the array `[5, 7, 7, 8, 8, 10]` is indeed indices `3` through `4`.

---

## 🧠 Example 2: `nums = [1, 2, 3, 4, 5]`, `target = 6`

### 🔹 Step 1 — Find first occurrence (`isFirst = true`)

| Step | start | end | mid | nums[mid] | Action                           |
| ---- | ----- | --- | --- | --------- | -------------------------------- |
| 1    | 0     | 4   | 2   | 3         | 3 < 6 → move right → `start = 3` |
| 2    | 3     | 4   | 3   | 4         | 4 < 6 → move right → `start = 4` |
| 3    | 4     | 4   | 4   | 5         | 5 < 6 → move right → `start = 5` |
| 4    | 5     | 4   | —   | —         | loop exits → return `-1`         |

Target `6` not found → return `[-1, -1]`.

---

✅ **Final Output:** `[-1, -1]`

---

## 🧠 Example 3: `nums = [2, 2, 2, 2, 2]`, `target = 2`

### 🔹 Step 1 — Find first occurrence (`isFirst = true`)

| Step | start | end | mid | nums[mid] | Action                                                                                |
| ---- | ----- | --- | --- | --------- | ------------------------------------------------------------------------------------- |
| 1    | 0     | 4   | 2   | 2         | Found 2 → check left neighbor → `nums[1] = 2`, duplicate left → move left → `end = 1` |
| 2    | 0     | 1   | 0   | 2         | Found 2 → `mid == start` → ✅ return `0`                                               |

**First = 0**

---

### 🔹 Step 2 — Find last occurrence (`isFirst = false`)

| Step | start | end | mid | nums[mid] | Action                                                                                   |
| ---- | ----- | --- | --- | --------- | ---------------------------------------------------------------------------------------- |
| 1    | 0     | 4   | 2   | 2         | Found 2 → check right neighbor `nums[3] = 2`, duplicate right → move right → `start = 3` |
| 2    | 3     | 4   | 3   | 2         | Found 2 → check right neighbor `nums[4] = 2`, duplicate right → `start = 4`              |
| 3    | 4     | 4   | 4   | 2         | Found 2 → `mid == end` → ✅ return `4`                                                    |

**Last = 4**

---

✅ **Final Output:** `[0, 4]`

---

## 💡 Summary of Logic

1. **Binary Search** is used twice — once to find the **first index**, and once for the **last**.
2. **Key difference:**

   * When searching for the first index → move `end` left if duplicates exist.
   * When searching for the last index → move `start` right if duplicates exist.
3. **Time complexity:** `O(log n)` for each search → total `O(log n)`.
4. **Space complexity:** `O(1)` (only variables used).

---

Would you like me to visualize this algorithm next with a **step-by-step diagram or ASCII illustration** (e.g., how `start`, `mid`, `end` move)? It can make the concept crystal clear visually.
