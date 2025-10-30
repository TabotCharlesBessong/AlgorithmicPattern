
#include <iostream>
#include <unordered_map>
#include <string>
usinfg namespace std;

class Solution {
  public:
    unordered_map<string,int> values = {
      {"I", 1},
      {"V", 5},
      {"X", 10},
      {"L", 50},
      {"C", 100},
      {"D", 500},
      {"M", 1000},
      {"IV", 4},
      {"IX", 9},
      {"XL", 40},
      {"XC", 90},
      {"CD", 400},
      {"CM", 900}
    }

    int romanToInt(string s) {
      int result = 0;
      for (int i = 0; i < s.length(); ) {
        if (i + 1 < s.length()) {
          string doubleSymbol = s.substr(i, 2);
          if (values.find(doubleSymbol) != values.end()) {
            result += values[doubleSymbol];
            i += 2;
            continue;
          }
        }
        string singleSymbol = s.substr(i, 1);
        result += values[singleSymbol];
        i += 1;
      }
      return result;
    }
};

int main() {
  Solution solution;
  string roman = "MCMXCIV";
  int result = solution.romanToInt(roman);
  cout << "The integer value of Roman numeral " << roman << " is: " << result << endl;
  return 0;
}