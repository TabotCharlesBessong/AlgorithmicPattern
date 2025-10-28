#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.length() != t.length())
      return false;

    vector<int> charCounts(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
      charCounts[s[i] - 'a']++;
      charCounts[t[i] - 'a']--;
    }

    for (int count : charCounts)
    {
      if (count != 0)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  cout << boolalpha;
  cout << sol.isAnagram("anagram", "nagaram") << endl; // Output: true
  cout << sol.isAnagram("rat", "car") << endl;         // Output: false
  return 0;
}
