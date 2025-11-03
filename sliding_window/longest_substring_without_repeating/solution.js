
const lengthOfLongestSubstring = (s) => {
  if(!s || s.length === 0) return 0;
  if(s.length === 1) return 1;

  let left = 0
  let right = 0
  let ans = 0
  const set = new Set();

  while(right < s.length) {
    const c = s[right];
    while(set.has(c)){
      set.delete(s[left]);
      left++;
    }
    set.add(c);
    ans = Math.max(ans, right - left + 1);
    right++;
  }
  return ans;
}

// example usage
console.log(lengthOfLongestSubstring("abcabcbb")); // Output: 3
console.log(lengthOfLongestSubstring("pwwkew")); // Output: 3