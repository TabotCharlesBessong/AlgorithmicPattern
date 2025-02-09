function strongPasswordChecker(
  pw,
  minLength = 6,
  maxLength = 20,
  maxRepeat = 2
) {
  let re = new RegExp(`(.)\\1{0,${maxRepeat}}(?=\\1{${maxRepeat}})`, "g");
  let changes = (pw.match(re) || []).map((s) => s.length).sort((a, b) => b - a);

  let toRemove = pw.length - maxLength;
  while (changes.at(-1) <= toRemove) {
    toRemove -= changes.pop();
  }

  let numChanges = Math.max(
    changes.length,
    !/[a-z]/.test(pw) + !/[A-Z]/.test(pw) + !/[0-9]/.test(pw)
  );
  return Math.max(
    minLength - pw.length,
    numChanges + Math.max(0, pw.length - maxLength)
  );
}

const breakSubstringsWithDeletions = (substringLengths, numDeletions) => {
  while (numDeletions > 0) {
    let bestIdx = -1;
    let minMod = Infinity;

    for (let i = 0; i < substringLengths.length; i++) {
      if (substringLengths[i] >= 3 && substringLengths[i] % 3 < minMod) {
        bestIdx = i;
        minMod = substringLengths[i] % 3;
      }
    }

    if (bestIdx === -1) break;
    substringLengths[bestIdx]--;
    numDeletions--;
  }
};

const countSubstringsLengths = (s) => {
  let result = [1];
  let lastSeen = s[0];

  for (let i = 1; i < s.length; i++) {
    if (s[i] === lastSeen) {
      result[result.length - 1]++;
    } else {
      result.push(1);
      lastSeen = s[i];
    }
  }

  return result;
};

const strongPasswordChecker = (s) => {
  const lowercase = new Set("abcdefghijklmnopqrstuvwxyz");
  const uppercase = new Set("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  const digits = new Set("0123456789");

  const numDeletions = Math.max(0, s.length - 20);

  let hasLower = [...s].some((c) => lowercase.has(c));
  let hasUpper = [...s].some((c) => uppercase.has(c));
  let hasDigit = [...s].some((c) => digits.has(c));
  let numMissingTypes = !hasLower + !hasUpper + !hasDigit;

  let substringLengths = countSubstringsLengths(s);
  breakSubstringsWithDeletions(substringLengths, numDeletions);
  let numSubstringBreaks = substringLengths
    .filter((len) => len >= 3)
    .reduce((sum, len) => sum + Math.floor(len / 3), 0);

  let numInsertions = Math.max(0, 6 - s.length);
  console.log(numDeletions, numInsertions, numMissingTypes, numSubstringBreaks);

  return (
    numDeletions + Math.max(numMissingTypes, numInsertions, numSubstringBreaks)
  );
};

// Example Usage
console.log(strongPasswordChecker("a")); // Output: 5
console.log(strongPasswordChecker("aaa111")); // Output: 2
console.log(strongPasswordChecker("aaaBBB111")); // Output: 3
console.log(strongPasswordChecker("AAAAAAAAAAAAA12345")); // Output: 4
console.log(strongPasswordChecker("aaabbbbcccccdddddd")); // Output: 5,

// ✅ Test Case
console.log(strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA")); // Expected: 23
