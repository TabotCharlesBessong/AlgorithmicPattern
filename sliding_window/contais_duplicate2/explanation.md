# Algorithmic walkthrough — *Contains Nearby Duplicate* using Sliding Window + HashSet

**Problem restatement (short):**
Given an integer array `nums` and an integer `k`, return `true` if there exist two distinct indices `i` and `j` such that `nums[i] == nums[j]` and `|i - j| <= k`. Otherwise return `false`.

We solve this with the **sliding window** pattern and a **hash set** to maintain the values currently inside the window of size at most `k`. The set gives O(1) average-time membership checks.

---

# Intuition (one-liner)

Maintain a set containing the last up-to-`k` numbers seen. For each new number at index `i`:

* If it’s already in the set → a duplicate exists within distance `≤ k` → return `true`.
* Otherwise add it. If the set grows larger than `k`, remove the element that just moved out of the window (`nums[i - k]`) so the set continues to represent a sliding window of size `k`.

---

# Algorithm (step-by-step)

1. Initialize an empty `HashSet<Integer> set`.
2. Iterate `i` from `0` to `nums.length - 1`:

   1. Let `val = nums[i]`.
   2. **Check membership:** If `set.contains(val)`, then some previous index `j` within the current window has `nums[j] == val`, and `|i - j| ≤ k`. **Return `true`.**
   3. **Add current value:** `set.add(val)`.
   4. **Enforce window size:** If `set.size() > k`, remove the element that left the window: `set.remove(nums[i - k])`.

      * This keeps the set representing at most the last `k` elements (the window of indices `(i-k+1)` through `i`).
3. If the loop completes with no duplicate found, **return `false`**.

---

# Why this works (invariant)

At the start of each loop iteration for index `i` (after the `contains` check and before possible removal), the `set` contains the values from indices `max(0, i - k)` through `i - 1`. That is, the set is the multiset of values in the previous up-to-`k` positions.

* If the current value `nums[i]` is already in `set`, it must match a value from some `j` in `[i-k, i-1]`, so `|i - j| ≤ k` and the condition is satisfied.
* If not, we add `nums[i]`. If the set grows > `k`, we remove `nums[i-k]` to slide the window forward. The invariant is preserved for the next iteration.

---

# Complexity

* **Time:** O(n) average — each element is added and removed from the set at most once; membership checks are O(1) average.
* **Space:** O(min(n, k)) — the set holds at most `k` distinct elements.

---

# Example walkthrough

Input: `nums = [1, 2, 3, 1, 4, 5]`, `k = 3`

We’ll show each iteration with: `i`, `nums[i]`, `set` before action, action, and result.

|  i | nums[i] | set (before) | action                                 | set (after)  | output?  |
| -: | :------ | :----------- | :------------------------------------- | :----------- | :------- |
|  0 | 1       | `{}`         | `contains(1)` → false; add 1           | `{1}`        | —        |
|  1 | 2       | `{1}`        | `contains(2)` → false; add 2           | `{1,2}`      | —        |
|  2 | 3       | `{1,2}`      | `contains(3)` → false; add 3           | `{1,2,3}`    | —        |
|  3 | 1       | `{1,2,3}`    | `contains(1)` → **true** → return true | (not needed) | **true** |

Explanation: at `i = 3` we check whether `1` is in the set of previous up-to-`k` elements (`i - k` = `0`, window is indices `0..2`). `1` is present (from index 0), and `|3 - 0| = 3 ≤ k`, so we correctly return `true`.

---

# Edge cases & notes

* **k = 0**: The window size is 0 — no two distinct indices `i != j` can satisfy `|i - j| ≤ 0`. Implementation detail: the code will check and then remove immediately (set size > 0) — result is `false` unless you adapt logic; typically `k == 0` → always `false`.
* **k ≥ nums.length**: The sliding window can grow to include the whole array; set may contain up to `n` elements. Complexity remains O(n).
* **Duplicate values outside the k-range**: They won’t trigger a `true` because we remove entries as they fall out of the window.
* **Why `set.size() > k` works**: After adding the current element the set size becomes window-size + 1; removing `nums[i - k]` restores size ≤ k and keeps the set aligned to the last `k` indices. This condition is equivalent to explicitly checking `if (i >= k) remove(nums[i-k])` but works correctly even for early indices because `set.size()` tracks how many elements are currently stored.

---

# Small correctness argument (informal)

* If algorithm returns `true`, we found `i` and some earlier `j` in the set such that `nums[i] == nums[j]` and because `j` is in the window `[i - k, i - 1]`, we have `|i - j| ≤ k`. So returned `true` is correct.
* If there exists a pair `(i, j)` with `i > j`, `nums[i] == nums[j]`, and `i - j ≤ k`, then when the loop reaches `i`, we will still have added `nums[j]` earlier and not yet removed it (because the window at `i` includes index `j`), so `set.contains(nums[i])` will be true and algorithm will return `true`. Thus the algorithm finds any valid pair.

---

# Pseudocode (compact)

```text
set = empty set
for i from 0 to len(nums)-1:
    if nums[i] in set:
        return true
    add nums[i] to set
    if size(set) > k:
        remove nums[i - k] from set
return false
```

---

If you want, I can:

* Show a visual animation-like sequence for a different example, or
* Provide formal invariants/proof, or
* Convert this explanation into an inline comment block for the code you provided. Which would you prefer?
