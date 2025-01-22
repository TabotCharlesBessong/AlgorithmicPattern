public class Solution {
  public int climbStairs(int n) {
    if (n <= 1)
      return 1;
    int[] dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }

  public static void main(String[] args) {
    Solution sol = new Solution();
    System.out.println(sol.climbStairs(3)); // Output: 3
    System.out.println(sol.climbStairs(5)); // Output: 8
  }
}
