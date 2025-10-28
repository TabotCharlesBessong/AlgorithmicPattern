#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    if (strs.empty())
      return {};

    unordered_map<string, vector<string>> ans;

    for (auto &s : strs)
    {
      vector<int> count(26, 0);
      for (char c : s)
      {
        count[c - 'a']++;
      }

      stringstream keyStream;
      for (int i = 0; i < 26; ++i)
      {
        keyStream << "#" << count[i];
      }
      string key = keyStream.str();
      ans[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &entry : ans)
    {
      result.push_back(entry.second);
    }
    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = sol.groupAnagrams(input);

  for (auto &group : result)
  {
    cout << "[ ";
    for (auto &word : group)
    {
      cout << word << " ";
    }
    cout << "] ";
  }
  cout << endl;

  return 0;
}
