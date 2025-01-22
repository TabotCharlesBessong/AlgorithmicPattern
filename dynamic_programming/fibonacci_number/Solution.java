

public class Solution {
  public int fib(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    int prev1 = 0, prev2 = 1;
    for (int i = 2; i <= n; i++) {
      int current = prev1 + prev2;
      prev1 = prev2;
      prev2 = current;
    }
    return prev2;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    System.out.println(solution.fib(10)); // Output: 55
  }
}
