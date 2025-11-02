function characterReplacement(s, k) {
  const occurrence = new Array(26).fill(0);
  let left = 0;
  let ans = 0;
  let maxOccurrence = 0;

  for (let right = 0; right < s.length; right++) {
    const index = s.charCodeAt(right) - 65;
    occurrence[index]++;
    maxOccurrence = Math.max(maxOccurrence, occurrence[index]);

    if (right - left + 1 - maxOccurrence > k) {
      occurrence[s.charCodeAt(left) - 65]--;
      left++;
    } else {
      ans = Math.max(ans, right - left + 1);
    }
  }

  return ans;
}

// Example Usage
console.log(characterReplacement("AABABBA", 1)); // Output: 4
