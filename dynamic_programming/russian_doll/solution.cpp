#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    if (envelopes.empty())
      return 0;

    // Step 1: Sort envelopes
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0]; });

    // Step 2: Extract heights and apply LIS
    vector<int> dp;
    for (auto &e : envelopes)
    {
      int h = e[1];
      auto it = lower_bound(dp.begin(), dp.end(), h);
      if (it == dp.end())
      {
        dp.push_back(h);
      }
      else
      {
        *it = h;
      }
    }

    return dp.size();
  }
};

int main()
{
  Solution solution;

  vector<vector<int>> envelopes1 = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
  cout << "Maximum number of envelopes: " << solution.maxEnvelopes(envelopes1) << endl;

  vector<vector<int>> envelopes2 = {{1, 1}, {1, 1}, {1, 1}};
  cout << "Maximum number of envelopes: " << solution.maxEnvelopes(envelopes2) << endl;

  return 0;
}
