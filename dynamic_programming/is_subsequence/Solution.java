public class Solution {
  public static boolean isSubsequence(String s, String t){
    int i = 0, j = 0;

    while (j < t.length()){
      if (i < s.length() && s.charAt(i) == t.charAt(j)){
        i++;
      }
      j++;
    }
    return i == s.length();
  }

  public static void main(String[] args) {
    String s = "abc", t = "ahbgdc";
    System.out.println(isSubsequence(s, t)); // Output: true
  }
}
