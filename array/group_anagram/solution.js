class Solution {
  groupAnagrams(strs) {
    if (strs.length === 0) return [];

    const ans = new Map();

    for (const s of strs) {
      const count = new Array(26).fill(0);
      for (const c of s) {
        count[c.charCodeAt(0) - "a".charCodeAt(0)]++;
      }

      const key = count.join("#");
      if (!ans.has(key)) ans.set(key, []);
      ans.get(key).push(s);
    }

    return Array.from(ans.values());
  }
}

// Example usage
const solution = new Solution();
const input = ["eat", "tea", "tan", "ate", "nat", "bat"];
console.log(solution.groupAnagrams(input));
// Output: [ [ 'eat', 'tea', 'ate' ], [ 'tan', 'nat' ], [ 'bat' ] ]
