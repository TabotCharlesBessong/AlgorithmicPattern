
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(const vector<string> &strs)
{
  if (strs.empty())
    return "";
  string prefix = strs[0];
  for (size_t i = 1; i < strs.size(); ++i)
  {
    while (strs[i].find(prefix) != 0)
    {
      prefix = prefix.substr(0, prefix.length() - 1);
      if (prefix.empty())
        return "";
    }
  }
  return prefix;
}

int main()
{
  vector<string> strs = {"flower", "flow", "flight"};
  cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;

  return 0;
}