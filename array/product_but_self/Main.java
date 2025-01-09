

import java.util.Arrays;


public class Main {

  public static int[] productExceptSelf(int[] nums) {
      int[] result = new int[nums.length];

      Arrays.fill(result,1);

      int left = 1, right = 1;

      for(int i = 0; i < nums.length; i++) {
        result[i] = left;
        left *= nums[i];
      }

      for(int i = nums.length - 1; i >= 0; i--) {
        result[i] *= right;
        right *= nums[i];
      }
      return result;
    }
    public static void main(String[] args) {
      int[] nums = { 2, 5, 3, 6 };
      int[] result = productExceptSelf(nums);
    System.out.println(Arrays.toString(result)); // Output: [90, 36, 60, 30]
  }
}
