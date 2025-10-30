class Solution {
  constructor() {
    this.values = {
      I: 1,
      V: 5,
      X: 10,
      L: 50,
      C: 100,
      D: 500,
      M: 1000,
      IV: 4,
      IX: 9,
      XL: 40,
      XC: 90,
      CD: 400,
      CM: 900,
    };
  }

  romanToInt(s) {
    let sum = 0;
    let i = 0;
    while (i < s.length) {
      if (i + 1 < s.length && this.values[s.substring(i, i + 2)]) {
        sum += this.values[s.substring(i, i + 2)];
        i += 2;
      } else {
        sum += this.values[s[i]];
        i += 1;
      }
    }
    return sum;
  }
}

// Example usage
const solution = new Solution();
console.log(solution.romanToInt("LVIII")); // Output: 58
