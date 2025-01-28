
public class Solution {
  public int maxRepeating(String sequence, String word) {
    int k = 0;
    String repeatedString = word;

    while (sequence.contains(repeatedString)) {
      k++;
      repeatedString += word;
    }

    return k;
  }

  public static void main(String[] args){
    Solution sol = new Solution();

    System.out.println(sol.maxRepeating("ababc", "ab")); // Output: 2
    System.out.println(sol.maxRepeating("ababc", "ba")); // Output: 1
    System.out.println(sol.maxRepeating("ababc", "ac")); // Output: 0
  }
}