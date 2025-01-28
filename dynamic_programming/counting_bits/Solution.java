import java.util.Arrays;

public class Solution {
  public static int[] countBits(int n) {
    int[] ans = new int[n + 1];
    for (int i = 1; i <= n; i++) {
      ans[i] = ans[i / 2] + (i % 2);
    }
    return ans;
  }

  public static void main(String[] args) {
    System.out.println(Arrays.toString(countBits(2))); // [0, 1, 1]
    System.out.println(Arrays.toString(countBits(5))); // [0, 1, 1, 2, 1, 2]
  }
}
