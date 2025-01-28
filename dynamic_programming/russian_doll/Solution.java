import java.util.Arrays;

class Solution {
  public int maxEnvelopes(int[][] envelopes) {
    if (envelopes.length == 0)
      return 0;

    // Step 1: Sort envelopes
    Arrays.sort(envelopes, (a, b) -> {
      if (a[0] == b[0])
        return b[1] - a[1];
      return a[0] - b[0];
    });

    // Step 2: Extract heights and apply LIS
    int[] dp = new int[envelopes.length];
    int len = 0;

    for (int[] e : envelopes) {
      int h = e[1];
      int pos = Arrays.binarySearch(dp, 0, len, h);
      if (pos < 0)
        pos = -(pos + 1);
      if (pos == len)
        len++;
      dp[pos] = h;
    }

    return len;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();

    int[][] envelopes1 = { { 5, 4 }, { 6, 4 }, { 6, 7 }, { 2, 3 } };
    System.out.println("Maximum number of envelopes: " + solution.maxEnvelopes(envelopes1));

    int[][] envelopes2 = { { 1, 1 }, { 1, 1 }, { 1, 1 } };
    System.out.println("Maximum number of envelopes: " + solution.maxEnvelopes(envelopes2));
  }
}
