package array.top_k_element;

import java.util.HashMap;
import java.util.Map;
import java.util.Queue;

public class Solution {
  public int[] topKFrequent(int[] nums, int k){
    if(k == nums.length){
      return nums;
    }

    Map<Integer, Integer> count = new HashMap<>();
    for(int n : nums){
      count.put(n, count.getOrDefault(n, 0) + 1);
    }

    Queue<Integer> heap = new java.util.PriorityQueue<>(
        (n1, n2) -> count.get(n1) - count.get(n2)
    );

    for(int n : count.keySet()){
      heap.add(n);
      if(heap.size() > k){
        heap.poll();
      }
    }

    int[] ans = new int[k];
    for(int i = 0; i < k; i++){
      ans[i] = heap.poll();
    }
    return ans;
  }
}
