#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
  int totalSteps = m + n - 2;
  int chooseSteps = min(m - 1, n - 1);

  long long result = 1;
  for (int i = 1; i <= chooseSteps; i++)
  {
    result *= totalSteps--;
    result /= i; // Integer division to prevent overflow
  }
  return result;
}

int main()
{
  cout << uniquePaths(3, 7) << endl;   // Output: 28
  cout << uniquePaths(3, 2) << endl;   // Output: 3
  cout << uniquePaths(10, 10) << endl; // Output: 48620
  return 0;
}
