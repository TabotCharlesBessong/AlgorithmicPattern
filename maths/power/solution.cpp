#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
  double myPow(double x, int n)
  {
    long long N = n; // Convert n to long long to handle INT_MIN safely
    if (N < 0)
    {
      x = 1 / x;
      N = -N;
    }

    return power(x, N);
  }

private:
  double power(double x, long long n)
  {
    if (n == 0)
      return 1;
    double half = power(x, n / 2);
    return (n % 2 == 0) ? half * half : half * half * x;
  }
};

int main()
{
  Solution solution;
  cout << solution.myPow(2.0, 10) << endl;      // Output: 1024
  cout << solution.myPow(2.0, -2) << endl;      // Output: 0.25
  cout << solution.myPow(2.0, INT_MIN) << endl; // Handle edge case safely
}
