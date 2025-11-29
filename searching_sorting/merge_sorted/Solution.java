public class Solution {
  public void merge(int[] nums1, int m, int[] nums2, int n) {
    // Pointers for nums1, nums2, and the end of the merged array
    int p1 = m - 1, p2 = n - 1, i = m + n - 1;

    // Merge in reverse order
    while (p2 >= 0) {
      if (p1 >= 0 && nums1[p1] > nums2[p2]) {
        nums1[i] = nums1[p1];
        p1--;
      } else {
        nums1[i] = nums2[p2];
        p2--;
      }
      i--;
    }
  }
}