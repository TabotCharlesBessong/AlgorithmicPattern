import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
  public static int leastInterval(char[] tasks, int n){
    Map<Character, Integer> freq = new HashMap<>();
    for(char c : tasks) freq.put(c, freq.getOrDefault(c, 0) + 1);

    List<Integer> counts = new ArrayList<>(freq.values());
    Collections.sort(counts,Collections.reverseOrder());

    int maxFreq = counts.get(0);
    int countMaxFreq = 0;
    for (int f : counts){
      if (f == maxFreq) countMaxFreq++;
    }

    return Math.max((maxFreq - 1) * (n + 1) + countMaxFreq, tasks.length);
  }

  public static void main(String[] args) {
    char[] tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;
    System.out.println(leastInterval(tasks, n)); // Output: 8
  }
}