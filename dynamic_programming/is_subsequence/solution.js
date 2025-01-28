const isSubsequence = (s, t) => {
  let i = 0,
    j = 0;
  while (j < t.length) {
    if (i < s.length && s[i] === t[j]) {
      i++;
    }
    j++;
  }
  return i === s.length;
};

// Example usage
console.log(isSubsequence("abc", "ahbgdc")); // true
console.log(isSubsequence("axc", "ahbgdc")); // false
