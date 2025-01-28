const isMatch = (s,p) => {
  let m = s.length, n = p.length;
  let dp = Array.from(Array(m+1), () => Array(n+1).fill(false));
  dp[0][0] = true;

  // initialize dp for patterns with "*"
  for (let j = 1; j <= n; j++) {
    if (p[j - 1] === '*') dp[0][j] = dp[0][j - 1];
  }

  // fill the  rest of the table
  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (p[j -1] === s[i - 1] || p[j - 1] === '?'){
        dp[i][j] = dp[i - 1][j - 1];
      }else if (p[j - 1] === '*'){
        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
      }
    }
  }

  return dp[m][n];
} 

// example usage

const s = "aa";
const p = "a*";

console.log(isMatch(s, p)); // true

const s2 = "ab";

console.log(isMatch(s2, p)); // false

const s3 = "aab";

console.log(isMatch(s3, p)); // true