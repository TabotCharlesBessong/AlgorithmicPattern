#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      ans[i] = ans[i / 2] + (i % 2);
    }
    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> result = solution.countBits(2);
  for (int num : result)
    cout << num << " ";
  cout << endl;

  result = solution.countBits(5);
  for (int num : result)
    cout << num << " ";
  cout << endl;
  return 0;
}
