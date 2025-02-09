import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
  public int findMaximizedCapital(int k, int w, int[] profits, int[] capital){
    int n = profits.length;
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    List<int[]> projects = new ArrayList<>();

    for (int i = 0; i < n; i++){
      projects.add(new int[]{capital[i], profits[i]});
    }

    projects.sort(Comparator.comparingInt(a -> a[0]));

    int i = 0;

    while (k-- > 0){
      while(i < n && projects.get(i)[0] <= w){
        maxHeap.offer(projects.get(i++)[1]);
      }

      if (maxHeap.isEmpty()){
        break;
      }
      w += maxHeap.poll();
    }

    return w;
  }

  public static void main(String[] args) {
    Solution sol = new Solution();
    System.out.println(sol.findMaximizedCapital(2, 0, new int[] { 1, 2, 3 }, new int[] { 0, 1, 1 })); // Expected: 4
  }
}