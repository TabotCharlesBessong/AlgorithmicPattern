import java.util.*;

public class Solution {
  private static final String[] ONES = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
  private static final String[] TEENS = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
      "Seventeen", "Eighteen", "Nineteen" };
  private static final String[] TENS = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
      "Ninety" };
  private static final String[] THOUSANDS = { "", "Thousand", "Million", "Billion" };

  public String numberToWords(int num) {
    if (num == 0) {
      return "Zero";
    }

    String result = "";
    int groupIndex = 0;

    while (num > 0) {
      int group = num % 1000;
      if (group != 0) {
        result = helper(group) + (THOUSANDS[groupIndex].isEmpty() ? "" : " " + THOUSANDS[groupIndex]) + " " + result;
      }
      num /= 1000;
      groupIndex++;
    }

    return result.trim();
  }

  private String helper(int num) {
    StringBuilder sb = new StringBuilder();
    if (num >= 100) {
      sb.append(ONES[num / 100]).append(" Hundred ");
      num %= 100;
    }
    if (num >= 20) {
      sb.append(TENS[num / 10]).append(" ");
      num %= 10;
    }
    if (num >= 10 && num < 20) {
      sb.append(TEENS[num - 10]).append(" ");
      return sb.toString().trim();
    }
    if (num > 0) {
      sb.append(ONES[num]).append(" ");
    }
    return sb.toString().trim();
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    System.out.println(solution.numberToWords(12345)); // Output: "Twelve Thousand Three Hundred Forty Five"
    System.out.println(solution.numberToWords(1234567)); // Output: "One Million Two Hundred Thirty Four Thousand Five
                                                         // Hundred Sixty Seven"
    System.out.println(solution.numberToWords(10)); // Output: "Ten"
    System.out.println(solution.numberToWords(0)); // Output: "Zero"
  }
}
