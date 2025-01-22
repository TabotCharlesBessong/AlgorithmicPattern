#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
  vector<int> getRow(int rowIndex){
    vector<int> row = {1};
    for (int i = 1; i <= rowIndex; i++){
      row.push_back(1);
      for (int j = i - 1; j > 0; j--){
        row[j] = row[j] + row[j-1];
      }
    }
    return row;
  }
};

int
main()
{
  Solution sol;
  vector<int> result = sol.getRow(4);
  for (int num : result)
  {
    cout << num << " ";
  }
  // Output: 1 4 6 4 1
  return 0;
}