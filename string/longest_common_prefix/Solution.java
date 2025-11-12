package string.longest_common_prefix;

public class Solution {
  public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    // Initialize the prefix as the first string
    String prefix = strs[0];

    // Compare the prefix with each string in the array
    for (int i = 1; i < strs.length; i++) {
      // Reduce the prefix until it matches the start of strs[i]
      while (strs[i].indexOf(prefix) != 0) {
        prefix = prefix.substring(0, prefix.length() - 1);
        if (prefix.isEmpty()) return "";
      }
    }
    return prefix;
  }
}
