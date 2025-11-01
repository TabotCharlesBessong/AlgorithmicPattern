Excellent — that’s one of the most elegant “Top K Frequent Elements” solutions using a **min-heap (priority queue)**!

Below you’ll find:
✅ The same algorithm implemented in **Python**, **JavaScript**, **Go**, and **C++**.
✅ A complete **algorithmic walkthrough in Markdown**, explaining *exactly* how it works step-by-step — with a sliding “heap” illustration showing its state at each stage.

---

# 🧠 Problem Recap: “Top K Frequent Elements”

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

Example:

```text
nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

---

# ⚙️ Java Reference Implementation

*(Already provided by you)*

```java
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;

public class Solution {
  public int[] topKFrequent(int[] nums, int k){
    if (k == nums.length) {
      return nums;
    }

    Map<Integer, Integer> count = new HashMap<>();
    for (int n : nums) {
      count.put(n, count.getOrDefault(n, 0) + 1);
    }

    Queue<Integer> heap = new java.util.PriorityQueue<>(
      (n1, n2) -> count.get(n1) - count.get(n2)
    );

    for (int n : count.keySet()) {
      heap.add(n);
      if (heap.size() > k) {
        heap.poll();
      }
    }

    int[] ans = new int[k];
    for (int i = 0; i < k; i++) {
      ans[i] = heap.poll();
    }
    return ans;
  }
}
```

---

# 🌍 Equivalent Implementations

---

## 🐍 Python Version

```python
import heapq
from collections import Counter

def topKFrequent(nums, k):
    if k == len(nums):
        return nums
    
    count = Counter(nums)
    heap = []

    for num, freq in count.items():
        heapq.heappush(heap, (freq, num))
        if len(heap) > k:
            heapq.heappop(heap)
    
    return [num for (freq, num) in heap]

# Example usage
print(topKFrequent([1,1,1,2,2,3], 2))  # Output: [2, 1]
```

---

## 💛 JavaScript Version

```javascript
function topKFrequent(nums, k) {
  if (k === nums.length) return nums;

  const count = new Map();
  for (const n of nums) {
    count.set(n, (count.get(n) || 0) + 1);
  }

  const heap = [];
  const comparator = (a, b) => count.get(a) - count.get(b);

  for (const n of count.keys()) {
    heap.push(n);
    heap.sort(comparator);
    if (heap.length > k) heap.shift();
  }

  return heap;
}

// Example usage
console.log(topKFrequent([1, 1, 1, 2, 2, 3], 2)); // Output: [2, 1]
```

*(JS lacks a built-in priority queue, so we simulate it with sorting — okay for small datasets.)*

---

## 💙 Go Version

```go
package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	num  int
	freq int
}

type MinHeap []Item

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].freq < h[j].freq }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Item))
}
func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[:n-1]
	return item
}

func topKFrequent(nums []int, k int) []int {
	count := make(map[int]int)
	for _, n := range nums {
		count[n]++
	}

	h := &MinHeap{}
	heap.Init(h)

	for n, freq := range count {
		heap.Push(h, Item{num: n, freq: freq})
		if h.Len() > k {
			heap.Pop(h)
		}
	}

	result := make([]int, h.Len())
	for i := 0; i < len(result); i++ {
		item := heap.Pop(h).(Item)
		result[i] = item.num
	}
	return result
}

func main() {
	fmt.Println(topKFrequent([]int{1, 1, 1, 2, 2, 3}, 2)) // Output: [2 1]
}
```

---

## 💠 C++ Version

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    if (k == nums.size()) return nums;

    unordered_map<int, int> count;
    for (int n : nums) count[n]++;

    auto cmp = [&count](int a, int b) { return count[a] > count[b]; };
    priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

    for (auto& [n, freq] : count) {
        heap.push(n);
        if (heap.size() > k) heap.pop();
    }

    vector<int> result;
    while (!heap.empty()) {
        result.push_back(heap.top());
        heap.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto res = topKFrequent(nums, k);
    for (int n : res) cout << n << " ";
    return 0; // Output: 2 1
}
```

---

# 🧩 Algorithmic Walkthrough

Let’s trace with:

```
nums = [1,1,1,2,2,3], k = 2
```

---

### **Step 1: Count frequencies**

Build a hashmap `count`:

| Element | Frequency |
| ------- | --------- |
| 1       | 3         |
| 2       | 2         |
| 3       | 1         |

---

### **Step 2: Initialize a min-heap**

We’ll use a *min-heap* of size at most `k`, where:

* The heap stores elements by their frequency.
* The smallest frequency stays on top.
* If the heap exceeds `k`, we pop the smallest frequency out.

---

### **Step 3: Insert elements one by one**

| Step | Current Num | Heap (freqs)                | Action                 |
| ---- | ----------- | --------------------------- | ---------------------- |
| 1    | 1 (freq 3)  | [1]                         | Added 1                |
| 2    | 2 (freq 2)  | [2, 1]                      | Added 2                |
| 3    | 3 (freq 1)  | [1, 2, 3] → size>2 → pop(3) | Removed least frequent |

Resulting heap:

```
[2 (freq 2), 1 (freq 3)]
```

---

### **Step 4: Extract heap elements**

Pop all elements → `[2, 1]`
These are the **two most frequent** elements.

---

### **Step 5: Output**

```
[1, 2] or [2, 1]  // order doesn’t matter
```

---

# 🎨 Visual Summary (Conceptual Diagram)

```
nums = [1, 1, 1, 2, 2, 3]
k = 2

Step 1 → Build frequency map:
  1:3 | 2:2 | 3:1

Step 2 → Push to min-heap (store smallest at top)
  [ (1,3), (2,2) ] → heap keeps 2 smallest freq

When (3,1) arrives → heap overflows (size 3) → remove smallest
  heap after pop → [ (1,3), (2,2) ]

Result → extract numbers → [1,2]
```

---

# 🧮 Complexity Analysis

| Operation                               | Complexity                            |
| --------------------------------------- | ------------------------------------- |
| Build frequency map                     | **O(n)**                              |
| Push/pop in heap (n elements, size k)** | **O(n log k)**                        |
| Extract k results                       | **O(k log k)**                        |
| **Total time complexity**               | **O(n log k)**                        |
| **Space complexity**                    | **O(n)** (for frequency map and heap) |

---

# ✅ Summary

| Step | What Happens              | Data Structure Used |
| ---- | ------------------------- | ------------------- |
| 1    | Count occurrences         | HashMap             |
| 2    | Maintain top `k` frequent | Min-Heap            |
| 3    | Output heap contents      | List                |

**Why this works efficiently:**
Instead of sorting all unique elements (O(n log n)), we maintain only the top `k` with a heap, achieving O(n log k).

---

Would you like me to generate a **series of visual PNG frames** showing the heap evolving (like we did for the sliding window one)? It makes this algorithm crystal clear visually — especially the `heap.add()` and `heap.poll()` transitions.
