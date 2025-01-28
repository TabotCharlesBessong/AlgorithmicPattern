#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
      return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (obstacleGrid[i][j] == 1)
        {
          dp[i][j] = 0;
        }
        else
        {
          if (i > 0)
            dp[i][j] += dp[i - 1][j];
          if (j > 0)
            dp[i][j] += dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};


// example usage

int main()
{
  Solution solution;

  vector<vector<int>> obstacleGrid = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
  };

  int result = solution.uniquePathsWithObstacles(obstacleGrid);
  cout << "Number of unique paths: " << result << endl; // Output: 2

  return 0;
}