
const minWindow = (s, t) => {
  if (!s.length || !t.length || s.length < t.length) return "";

  const mapT = {};
  for (const c of t) mapT[c] = (mapT[c] || 0) + 1;

  const required = Object.keys(mapT).length;
  let formed = 0;
  let l = 0,
    r = 0;
  const windowCount = {};
  let ans = [Infinity, 0, 0];

  while (r < s.length) {
    const c = s[r];
    windowCount[c] = (windowCount[c] || 0) + 1;

    if (mapT[c] && windowCount[c] === mapT[c]) formed++;

    while (l <= r && formed === required) {
      if (r - l + 1 < ans[0]) ans = [r - l + 1, l, r];
      const ch = s[l];
      windowCount[ch]--;
      if (mapT[ch] && windowCount[ch] < mapT[ch]) formed--;
      l++;
    }
    r++;
  }

  return ans[0] === Infinity ? "" : s.slice(ans[1], ans[2] + 1);
};

console.log(minWindow("ADOBECODEBANC", "ABC")); // "BANC"

