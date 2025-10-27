package hashset.contains_duplicate;

import java.util.HashSet;

public class solution {
  public boolean containsDuplicate(int[] nums){
    HashSet<Integer> seenNumbers = new HashSet<>();
    for (int num: nums){
      if (seenNumbers.contains(num)){
        return true;
      } else {
        seenNumbers.add(num);
      }
    }
    return false;
  }


  // example usage
  public static void main(String[] args) {
    solution sol = new solution();
    int[] nums = {1, 2, 3, 1};
    boolean result = sol.containsDuplicate(nums);
    System.out.println("Contains duplicate: " + result); // Output: true
  }
}

