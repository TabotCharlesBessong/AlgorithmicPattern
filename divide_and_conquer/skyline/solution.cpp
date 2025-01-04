#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    auto merge = [](vector<vector<int>> &left, vector<vector<int>> &right)
    {
      vector<vector<int>> result;
      int h1 = 0, h2 = 0;
      int i = 0, j = 0;

      while (i < left.size() && j < right.size())
      {
        int x, maxHeight;
        if (left[i][0] < right[j][0])
        {
          x = left[i][0];
          h1 = left[i][1];
          i++;
        }
        else if (left[i][0] > right[j][0])
        {
          x = right[j][0];
          h2 = right[j][1];
          j++;
        }
        else
        {
          x = left[i][0];
          h1 = left[i][1];
          h2 = right[j][1];
          i++;
          j++;
        }
        maxHeight = max(h1, h2);
        if (result.empty() || result.back()[1] != maxHeight)
        {
          result.push_back({x, maxHeight});
        }
      }
      result.insert(result.end(), left.begin() + i, left.end());
      result.insert(result.end(), right.begin() + j, right.end());
      return result;
    };

    function<vector<vector<int>>(int, int)> divideAndConquer = [&](int start, int end)
    {
      if (start == end)
      {
        return vector<vector<int>>{{buildings[start][0], buildings[start][2]}, {buildings[start][1], 0}};
      }

      int mid = start + (end - start) / 2;
      auto left = divideAndConquer(start, mid);
      auto right = divideAndConquer(mid + 1, end);
      return merge(left, right);
    };

    return divideAndConquer(0, buildings.size() - 1);
  }
};
