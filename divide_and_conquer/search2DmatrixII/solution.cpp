#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    function<bool(int, int, int, int)> helper = [&](int rowStart, int rowEnd, int colStart, int colEnd)
    {
      if (rowStart > rowEnd || colStart > colEnd)
      {
        return false;
      }

      int midRow = (rowStart + rowEnd) / 2;
      int midCol = (colStart + colEnd) / 2;
      int midValue = matrix[midRow][midCol];

      if (midValue == target)
      {
        return true;
      }
      else if (midValue > target)
      {
        return helper(rowStart, midRow - 1, colStart, midCol - 1) ||
               helper(rowStart, midRow - 1, midCol, colEnd) ||
               helper(midRow, rowEnd, colStart, midCol - 1);
      }
      else
      {
        return helper(midRow + 1, rowEnd, midCol + 1, colEnd) ||
               helper(rowStart, midRow, midCol + 1, colEnd) ||
               helper(midRow + 1, rowEnd, colStart, midCol);
      }
    };

    if (matrix.empty() || matrix[0].empty())
    {
      return false;
    }
    return helper(0, matrix.size() - 1, 0, matrix[0].size() - 1);
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {1, 4, 7, 11, 15},
      {2, 5, 8, 12, 19},
      {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}};
  int target = 5;
  Solution solution;
  cout << (solution.searchMatrix(matrix, target) ? "true" : "false") << endl;
  return 0;
}
