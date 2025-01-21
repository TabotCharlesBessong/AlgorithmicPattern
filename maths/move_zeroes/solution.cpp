#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix){
      int m = matrix.size();
      int n = matrix[0].size();
      bool rowZero = false, colZero = false;

      // check if first row needs to be zero
      for(int j = 0; j < n; ++j){
        if(matrix[0][j] == 0){
          rowZero = true;
          break;
        }
      }
      
      // check if first column needs to be zero
      for(int i = 0; i < m; ++i){
        if(matrix[i][0] == 0){
          colZero = true;
          break;
        }
      }
      
      // use first row and column to mark zero rows and columns
      for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
          if(matrix[i][j] == 0){
            matrix[i][0] = matrix[0][j] = 0;
          }
        }
      }

      // set rows to zero based on markers
      for (int i = 1; i < m; ++i){
        if(matrix[i][0] == 0){
          for (int j = 1; j < n; ++j){
            matrix[i][j] = 0;
          }
        }
      }
      
      // set columns to zero based on markers
      for (int j = 1; j < n; ++j){
        if (matrix[0][j] == 0){
          for (int i = 1; i < m; ++i){
            matrix[i][j] = 0;
          }
        }
      }

      // set first row to zero if needed
      if(rowZero){
        for (int j = 0; j < n; ++j){
          matrix[0][j] = 0;
        }
      }

      // set columns to zero if needed
      if(colZero){
        for (int i = 0; i < m; ++i){
          matrix[i][0] = 0;
        }
      }
    }
};

int
main()
{
  Solution solution;
  vector<vector<int>> matrix = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};

  vector<vector<int>> matrix1 = {
      {0,1,2,0},
      {3,4,5,2},
      {1,3,1,5}};

  solution.setZeroes(matrix);
  solution.setZeroes(matrix1);

  // Print the matrix
  for (const auto &row : matrix)
  {
    for (int num : row)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  // Print the matrix
  for (const auto &row : matrix1)
  {
    for (int num : row)
    {
      cout << num << " ";
    }
    cout << endl;
  }
}