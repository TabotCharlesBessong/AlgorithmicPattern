package array.first_missing_positive;

public class Solution {
  public int firstMissingPositive(int[] nums){
    int n = nums.length;

    int contains = 0;
    for (int i = 0; i < nums.length; i++){
      if (nums[i] == 1){
        contains++;
        break;
      }
    }

    if (contains == 0) {
      return 1;
    }

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] <= 0 || nums[i] > n) {
        nums[i] = 1;
      }
    }

    for (int i = 0; i < nums.length; i++) {
      int num = Math.abs(nums[i]);
      if (num == n) {
        nums[0] = -Math.abs(nums[0]);
      } else {
        nums[num] = -Math.abs(nums[num]);
      }
    }

    for (int i = 1; i < n; i++) {
      if (nums[i] > 0) {
        return i;
      }
    }

    if (nums[0] > 0) {
      return n;
    }

    return n+1;
  }
}
