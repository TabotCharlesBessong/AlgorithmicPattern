
package sliding_window.longest_repeating_character;

class Solution {
  public int characterReplacement(String s, int k){
    int[] occurence = new int[26];
    int left = 0;
    int ans = 0;
    int maxOccurrence = 0;

    for (int right = 0; right < s.length(); right++){
      maxOccurrence = Math.max(maxOccurrence, ++occurence[s.charAt(right) - 'A']);
      if(right - left + 1 - maxOccurrence > k){
        occurence[s.charAt(left) - 'A']--;
        left++;
      } else {
        ans = Math.max(ans, right - left + 1);
      }
    }
    return ans;
  }
}