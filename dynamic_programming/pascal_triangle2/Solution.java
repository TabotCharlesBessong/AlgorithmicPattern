import java.util.*;

public class Solution {
  public List<Integer> getRow(int rowIndex) {
    List<Integer> row = new ArrayList<>();
    row.add(1);
    for (int i = 1; i <= rowIndex; i++) {
      row.add(1);
      for (int j = i - 1; j > 0; j--) {
        row.set(j, row.get(j) + row.get(j - 1));
      }
    }
    return row;
  }

  public static void main(String[] args) {
    Solution sol = new Solution();
    System.out.println(sol.getRow(4)); // Output: [1, 4, 6, 4, 1]
  }
}
