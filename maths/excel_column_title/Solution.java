package maths.excel_column_title;

public class Solution {
  public String convertToTitle(int n) {
    StringBuilder result = new StringBuilder();
    while (n > 0) {
      n--;
      result.append((char) ('A' + n % 26));
      n /= 26;
    }
    return result.reverse().toString();
  }

  public static void main(String[] args) {
    Solution sol = new Solution();
    System.out.println(sol.convertToTitle(28)); // Output: "AB"
  }
}
