import java.util.*;

public class Solution {
  public static int minimumBoxes(int[] apple, int[] capacity) {
    int totalApples = Arrays.stream(apple).sum();
    Integer[] boxCapacities = Arrays.stream(capacity).boxed().toArray(Integer[]::new);
    Arrays.sort(boxCapacities, Collections.reverseOrder());
    int boxesUsed = 0;

    for (int cap : boxCapacities) {
      totalApples -= cap;
      boxesUsed++;
      if (totalApples <= 0)
        return boxesUsed;
    }

    return boxesUsed;
  }

  public static void main(String[] args) {
    int[] apple = { 1, 3, 2 };
    int[] capacity = { 4, 3, 1, 5, 2 };
    System.out.println(minimumBoxes(apple, capacity)); // Output: 2
  }
}
