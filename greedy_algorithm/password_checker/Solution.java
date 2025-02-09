public class Solution {
  public static int strongPasswordChecker(String password) {
    int n = password.length();
    boolean hasLower = false, hasUpper = false, hasDigit = false;
    int repeatChanges = 0, toDelete = Math.max(n - 20, 0);
    int[] buckets = new int[3];

    for (int i = 0; i < n;) {
      char ch = password.charAt(i);
      if (Character.isLowerCase(ch))
        hasLower = true;
      if (Character.isUpperCase(ch))
        hasUpper = true;
      if (Character.isDigit(ch))
        hasDigit = true;

      int start = i;
      while (i < n && password.charAt(i) == password.charAt(start))
        i++;
      int length = i - start;

      if (length >= 3) {
        repeatChanges += length / 3;
        buckets[length % 3]++;
      }
    }

    int missingTypes = 3 - (hasLower ? 1 : 0) - (hasUpper ? 1 : 0) - (hasDigit ? 1 : 0);

    if (n < 6)
      return Math.max(6 - n, missingTypes);

    if (n <= 20)
      return Math.max(repeatChanges, missingTypes);

    if (toDelete > 0) {
      int use = Math.min(toDelete, buckets[0]);
      repeatChanges -= use;
      toDelete -= use;

      use = Math.min(toDelete, buckets[1] * 2);
      repeatChanges -= use / 2;
      toDelete -= use;

      use = Math.min(toDelete, buckets[2] * 3);
      repeatChanges -= use / 3;
      toDelete -= use;
    }

    return toDelete + Math.max(repeatChanges, missingTypes);
  }

  public static void main(String[] args) {
    System.out.println(strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA")); // Expected: 23
  }
}
