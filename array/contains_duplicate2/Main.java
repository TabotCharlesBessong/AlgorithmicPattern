import java.util.HashMap;

public class Main {
  public static boolean containsNearbyDuplicate(int[] nums, int k) {
      HashMap<Integer, Integer> seen = new HashMap<>();
  
      for (int i = 0; i < nums.length; i++) {
        if (seen.containsKey(nums[i]) && i - seen.get(nums[i]) <= k) {
          return true;
        }
        seen.put(nums[i], i);
      }
  
      return false;
    }
  
    public static void main(String[] args) {
      // Solution solution = new Solution();
      int[] nums = { 1, 2, 3, 1 };
      int k = 3;
      System.out.println(containsNearbyDuplicate(nums, k)); // Output: true
  }
}
