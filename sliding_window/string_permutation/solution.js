function checkInclusion(s1, s2) {
  if (s1.length > s2.length) return false;

  const s1Map = Array(26).fill(0);
  const s2Map = Array(26).fill(0);
  const aCharCode = "a".charCodeAt(0);

  for (let i = 0; i < s1.length; i++) {
    s1Map[s1.charCodeAt(i) - aCharCode]++;
    s2Map[s2.charCodeAt(i) - aCharCode]++;
  }

  const matches = (a, b) => a.every((v, i) => v === b[i]);

  for (let i = 0; i < s2.length - s1.length; i++) {
    if (matches(s1Map, s2Map)) return true;

    s2Map[s2.charCodeAt(i + s1.length) - aCharCode]++;
    s2Map[s2.charCodeAt(i) - aCharCode]--;
  }

  return matches(s1Map, s2Map);
}

// Example usage:
console.log(checkInclusion("ab", "eidbaooo")); // true
console.log(checkInclusion("ab", "eidboaoo")); // false
