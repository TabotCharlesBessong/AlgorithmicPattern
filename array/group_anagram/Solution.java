package array.group_anagram;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
  public List<List<String>> groupAnagrams(String[] strs){
    if (strs.length == 0){
      return new ArrayList<>();
    }
    Map<String, List<String>> ans = new HashMap<>();
    
    int[] count = new int[26];
    for (String s : strs){
      Arrays.fill(count, 0);
      for (char c : s.toCharArray()){
        count[c - 'a']++;
      }
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < 26; i++){
        sb.append('#');
        sb.append(count[i]);
      }
      String key = sb.toString();
      if (!ans.containsKey(key)){
        ans.put(key, new ArrayList<>());
      }
      ans.get(key).add(s);
    }
    return new ArrayList<>(ans.values());
  }


}

// example usage
class Main {
  public static void main(String[] args) {
    Solution solution = new Solution();
    String[] input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    List<List<String>> result = solution.groupAnagrams(input);
    System.out.println(result);
  }
}
