#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2)
{
  if (s1.size() > s2.size())
    return false;

  vector<int> s1Map(26, 0), s2Map(26, 0);

  for (int i = 0; i < s1.size(); i++)
  {
    s1Map[s1[i] - 'a']++;
    s2Map[s2[i] - 'a']++;
  }

  auto matches = [&](vector<int> &a, vector<int> &b)
  {
    return a == b;
  };

  for (int i = 0; i < s2.size() - s1.size(); i++)
  {
    if (matches(s1Map, s2Map))
      return true;
    s2Map[s2[i + s1.size()] - 'a']++;
    s2Map[s2[i] - 'a']--;
  }

  return matches(s1Map, s2Map);
}

int main()
{
  cout << boolalpha;
  cout << checkInclusion("ab", "eidbaooo") << endl; // true
  cout << checkInclusion("ab", "eidboaoo") << endl; // false
}
