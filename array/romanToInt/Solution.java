package array.romanToInt;

import java.util.HashMap;
import java.util.Map;

class Solution {
  public Map<String, Integer> values = new HashMap<>() {{
    put("I", 1);
    put("V", 5);
    put("X", 10);
    put("L", 50);
    put("C", 100);
    put("D", 500);
    put("M", 1000);
    put("IV", 4);
    put("IX", 9);
    put("XL", 40);
    put("XC", 90);
    put("CD", 400);
    put("CM", 900);
  }};

  public int romanToInt(String s) {
    int sum = 0;
    int i = 0;

    while (i < s.length()) {
      if (i + 1 < s.length()) {
        String doubleSymbol = s.substring(i, i + 2);
        if (values.containsKey(doubleSymbol)) {
          sum += values.get(doubleSymbol);
          i += 2;
          continue;
        }
      }
      sum += values.get(s.substring(i, i + 1));
      i += 1;
    }

    return sum;
  }
}