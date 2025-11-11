Perfect — let’s take a **longer example** (length 5) and do a **step-by-step algorithmic walkthrough** of how the **Next Permutation** algorithm works.
We’ll use **3 examples** again, each showing a different situation (pivot in middle, near start, and no pivot).

---

## 🔹 Algorithm recap (for reference)

Given an array `nums`:

1. Find the **pivot index `i`** such that `nums[i] < nums[i+1]` scanning from right to left.
   (This identifies where the sequence stops increasing.)
2. If such an `i` exists:

   * Find the **rightmost element `j`** greater than `nums[i]`.
   * Swap `nums[i]` and `nums[j]`.
3. Reverse the subarray from `i+1` to the end.

This gives the **next lexicographically greater permutation**.

---

## 🧩 Example 1 — Pivot in the middle

**Input:** `[1, 2, 3, 5, 4]`

We expect: **next permutation = `[1, 2, 4, 3, 5]`**

---

### Step 1 — Find pivot `i`

Start scanning from right:

* Compare `5` and `4` → `5 >= 4` ✅ → move left
* Compare `3` and `5` → `3 < 5` ❌ → **pivot found at i = 2 (value 3)**

---

### Step 2 — Find rightmost element greater than pivot

We look for `j` (rightmost number > 3):
From right → check `4 > 3` ✅ → `j = 4` (value `4`).

---

### Step 3 — Swap pivot and `j`

Swap `nums[2]` and `nums[4]`:
Array becomes → `[1, 2, 4, 5, 3]`.

---

### Step 4 — Reverse suffix (i+1..end)

Suffix starts from `i+1 = 3`: `[5, 3]` → reverse → `[3, 5]`.

Final array → **`[1, 2, 4, 3, 5]` ✅**

---

## 🧩 Example 2 — Pivot near the beginning

**Input:** `[1, 5, 4, 3, 2]`

We expect: **next permutation = `[2, 1, 3, 4, 5]`**

---

### Step 1 — Find pivot `i`

Scan from right:

* `3 >= 2` ✅ → continue
* `4 >= 3` ✅ → continue
* `5 >= 4` ✅ → continue
* `1 < 5` ❌ → **pivot = 0 (value 1)**

---

### Step 2 — Find rightmost element greater than pivot

Find `j` where `nums[j] > 1`:
From right → last element `2 > 1` ✅ → `j = 4`.

---

### Step 3 — Swap pivot and `j`

Swap `nums[0]` and `nums[4]` → array becomes `[2, 5, 4, 3, 1]`.

---

### Step 4 — Reverse suffix (i+1..end)

Suffix from index `1` to `4`: `[5, 4, 3, 1]` → reverse → `[1, 3, 4, 5]`.

Final array → **`[2, 1, 3, 4, 5]` ✅**

---

## 🧩 Example 3 — Entire array descending (last permutation)

**Input:** `[5, 4, 3, 2, 1]`

We expect: **next permutation = `[1, 2, 3, 4, 5]`**

---

### Step 1 — Find pivot `i`

Scan from right:

* `2 >= 1` ✅
* `3 >= 2` ✅
* `4 >= 3` ✅
* `5 >= 4` ✅
  No element where `nums[i] < nums[i+1]` → **no pivot found (`i = -1`)**

---

### Step 2 — No swap (since no pivot)

---

### Step 3 — Reverse entire array

Reverse `[5, 4, 3, 2, 1]` → `[1, 2, 3, 4, 5]`.

Final array → **`[1, 2, 3, 4, 5]` ✅**

---

## 🧠 Why it works

The key is that the **rightmost ascending pair** (`nums[i] < nums[i+1]`) is the *last place* where you can increase the permutation slightly while keeping it as small as possible afterward.

* Swapping `nums[i]` with the **next larger element to its right** ensures the increase.
* Reversing the suffix ensures that the remaining digits are in the smallest possible order.

---

## ⚙️ Time & Space Complexity

* **Time:** `O(n)`
  (Each of the 3 scans—find pivot, find swap target, reverse—is linear.)
* **Space:** `O(1)` (In-place)

---

Would you like me to include a **dry-run trace** (showing variable values `i`, `j`, `nums` after each step) for one of these examples (say Example 2)? It’s great for debugging and visual clarity.
