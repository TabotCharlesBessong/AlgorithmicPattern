var uniquePathsWithObstacles = function (obstacleGrid) {
  let m = obstacleGrid.length,
    n = obstacleGrid[0].length;

  if (obstacleGrid[0][0] === 1 || obstacleGrid[m - 1][n - 1] === 1) return 0;

  let dp = Array.from({ length: m }, () => Array(n).fill(0));
  dp[0][0] = 1;

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (obstacleGrid[i][j] === 1) {
        dp[i][j] = 0;
      } else {
        if (i > 0) dp[i][j] += dp[i - 1][j];
        if (j > 0) dp[i][j] += dp[i][j - 1];
      }
    }
  }

  return dp[m - 1][n - 1];
};


// example usage

let obstacleGrid = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
];

console.log(uniquePathsWithObstacles(obstacleGrid)); // Output: 2

let obstacleGrid2 = [
  [0, 1, 0],
  [0, 0, 0],
  [0, 1, 0]

]

console.log(uniquePathsWithObstacles(obstacleGrid2)); // Output: 1