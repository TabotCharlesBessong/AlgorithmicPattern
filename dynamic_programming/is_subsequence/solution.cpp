#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    int i = 0, j = 0;
    while (j < t.length())
    {
      if (i < s.length() && s[i] == t[j])
      {
        i++;
      }
      j++;
    }
    return i == s.length();
  }
};

int main()
{
  Solution solution;
  cout << solution.isSubsequence("abc", "ahbgdc") << endl; // true
  cout << solution.isSubsequence("axc", "ahbgdc") << endl; // false
  return 0;
}
