package searching_sorting.largest_element;

import java.util.Arrays;
import java.util.Comparator;

public class Solution {
  public String largestNumber(int[] nums){
    String[] asStrs = new String[nums.length];
    for (int i = 0; i < nums.length; i++){
      asStrs[i] = String.valueOf(nums[i]);
    }

    // sort strings according to custom comparator
    Arrays.sort(asStrs, new Comparator<String>() {
      public int compare(String a, String b){
        String order1 = a + b;
        String order2 = b + a;
        return order2.compareTo(order1);
      }
    });

    // If after being sorted, the largest number is `0`, the entire number is zero
    if(asStrs[0].equals("0")){
      return "0";
    }

    // Build largest number from sorted array
    StringBuilder largestNumberStr = new StringBuilder();
    for (String numAsStr : asStrs){
      largestNumberStr.append(numAsStr);
    }

    return largestNumberStr.toString();
  }
}
