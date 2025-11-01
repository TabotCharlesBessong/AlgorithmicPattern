# Detailed walkthrough — *Group Anagrams* (frequency-array + hashmap)

**Problem:** Given an array of strings, group the anagrams together.
Example input we'll use throughout:

```text
["eat", "tea", "tan", "ate", "nat", "bat"]
```

**High-level idea:**
For every word, compute a *signature* that is identical for all anagrams of that word. We use a **frequency array of 26 counts** (one per lowercase letter `a`–`z`) as the signature, then convert that frequency array into a string key (e.g. `"1#0#0#...#1#..."`) and use a hashmap (`Map<String,List<String>>`) from that key → list of original words. All words with the same key are anagrams → they get collected into the same list.

---

## Code sketch (JS/Java style pseudocode)

```text
map = empty hashmap
for s in strs:
    count = [0]*26
    for c in s:
        count[c - 'a'] += 1
    key = join(count with separator '#')
    if key not in map:
        map[key] = []
    map[key].append(s)
return values(map)  // list of lists
```

---

## Walkthrough with state changes (step-by-step)

We'll show, for each word:

1. the word,
2. the computed frequency counts (only non-zero entries shown for clarity),
3. the string key (conceptual),
4. the hashmap state after processing that word.

### Start

```
map = {}
```

---

### Step 1 — Process `"eat"`

* Build count array:

  * `e` → +1
  * `a` → +1
  * `t` → +1

Representation (full would be 26 entries; simplified showing non-zero):

```
count: a:1, e:1, t:1
```

* Key (conceptual):
  `"1 at a, 1 at e, 1 at t"` → implementation uses something like `"1#0#0#...#1#...#1#..."`.
* Insert into map:

```
map = {
  key_for("eat") : ["eat"]
}
```

(visual)

```
map:
  "1#0#...#1#...#1#..."  -> ["eat"]
```

---

### Step 2 — Process `"tea"`

* Build count array:

  * `t`:1, `e`:1, `a`:1  → **same counts as "eat"**

```
count: a:1, e:1, t:1
```

* Key: **identical to key_for("eat")**
* Map insertion: append to existing list

```
map = {
  key_for("eat/tea") : ["eat", "tea"]
}
```

(visual)

```
map:
  "1#0#...#1#...#1#..."  -> ["eat", "tea"]
```

**Why this works:** `"eat"` and `"tea"` produce the exact same frequency signature so they map to the same key.

---

### Step 3 — Process `"tan"`

* Build count array:

  * `t`:1, `a`:1, `n`:1

```
count: a:1, n:1, t:1
```

* Key: different from previous (because `n` present, `e` absent).
* Insert new list:

```
map = {
  key_for("eat/tea"): ["eat", "tea"],
  key_for("tan")    : ["tan"]
}
```

(visual)

```
map:
  "1#0#...#1_e_...#1_t_..."  -> ["eat","tea"]
  "1#0#...#1_n_...#1_t_..."  -> ["tan"]
```

---

### Step 4 — Process `"ate"`

* Build count array:

  * `a`:1, `t`:1, `e`:1 → **same as "eat"**

```
count: a:1, e:1, t:1
```

* Key: matches `key_for("eat/tea")`
* Append:

```
map = {
  key_for("eat/tea") : ["eat", "tea", "ate"],
  key_for("tan")     : ["tan"]
}
```

---

### Step 5 — Process `"nat"`

* Build count array:

  * `n`:1, `a`:1, `t`:1 → **same as "tan"**

```
count: a:1, n:1, t:1
```

* Key: matches `key_for("tan")`
* Append:

```
map = {
  key_for("eat/tea") : ["eat","tea","ate"],
  key_for("tan")     : ["tan","nat"]
}
```

---

### Step 6 — Process `"bat"`

* Build count array:

  * `b`:1, `a`:1, `t`:1

```
count: a:1, b:1, t:1
```

* New key; create new list:

```
map = {
  key_for("eat/tea"): ["eat","tea","ate"],
  key_for("tan")    : ["tan","nat"],
  key_for("bat")    : ["bat"]
}
```

---

### Final result

Return the values (order can vary because hashmap iteration order is unspecified):

```
[ ["eat","tea","ate"], ["tan","nat"], ["bat"] ]
```

---

## Visual (ASCII) — snapshot progression

Start:

```
{}
```

After "eat":

```
{ K1 -> ["eat"] }
```

After "tea":

```
{ K1 -> ["eat","tea"] }
```

After "tan":

```
{ K1 -> ["eat","tea"], K2 -> ["tan"] }
```

After "ate":

```
{ K1 -> ["eat","tea","ate"], K2 -> ["tan"] }
```

After "nat":

```
{ K1 -> ["eat","tea","ate"], K2 -> ["tan","nat"] }
```

After "bat":

```
{ K1 -> ["eat","tea","ate"], K2 -> ["tan","nat"], K3 -> ["bat"] }
```

(Where `K1` = signature for `a:1,e:1,t:1`, `K2` = `a:1,n:1,t:1`, `K3` = `a:1,b:1,t:1`)

---

## Important implementation details & alternatives

* **Why use a 26-element count array?**

  * It's O(L) to compute for a word of length L (increment counts while scanning the word).
  * It gives a canonical signature independent of character order (so all anagrams yield same signature).
* **Why convert to a string key with separators (e.g. `join('#')`)?**

  * Arrays are not valid hashmap keys in many languages — we need a stable string representation. Using a separator like `#` avoids ambiguous concatenations (e.g., counts `1,11` vs `11,1`).
* **Alternatives:**

  * Sort each word’s characters and use the sorted string as the key. Complexity: sorting each word is `O(L log L)` per word; frequency approach is `O(L)`.
  * Use a prime-based multiplicative hash (careful about overflow/commutativity).
* **Case sensitivity / character set:**

  * The code above assumes lowercase English letters `a`–`z`. For Unicode or mixed case, you must adapt the counting strategy (e.g., use a `Map<char,int>` or normalize characters).
* **Order of groups / words:**

  * The relative ordering of groups or items within groups depends on insertion order and language runtime; problem usually doesn’t require a specific order.

---

## Complexity

Let:

* `n` = number of strings (`strs.length`)

* `L` = maximum length of a string in `strs`

* **Time complexity:**
  For each word we build a 26-length count array in `O(L)` and convert it to a key in `O(26)` (constant), then do hashmap operations (amortized O(1)). Total: **O(n · L)**.

* **Space complexity:**

  * For the map keys and the groups: **O(n · L)** to store all strings in the output.
  * Additional temporary space: `O(26)` per word (constant), so negligible.

---

## Edge cases & correctness notes

* **Empty input**: return `[]`.
* **Single-letter strings**: grouped by letter.
* **Anagrams containing characters outside `a`–`z`**: current implementation would misbehave; adapt the count mapping.
* **Large alphabets**: if the alphabet is not small/limited (e.g., Unicode), use a dynamic map/dictionary keyed by character → count, then serialize that map.

---

## Summary

* The algorithm maps each word to a canonical signature (character frequency array → string) so that all anagrams share the same key.
* Using a hashmap from key → list collects anagrams in linear time with respect to total characters processed.
* This is fast and memory-efficient for typical lowercase-English anagram problems.

---

If you want, I can now:

* Produce a **frame-by-frame visual SVG or PNG sequence** showing the counts, the generated key, and the map being updated (one image per processed word), or
* Convert the walkthrough to inline comments in one of the language implementations. Which would you prefer?
