#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
  bool isThree(int n)
  {
    int k = sqrt(n);
    if (k * k != n)
      return false; // Check if n is a perfect square

    for (int i = 2; i <= sqrt(k); i++)
    {
      if (k % i == 0)
        return false; // Check if k is prime
    }

    return k > 1; // Ensure k is greater than 1
  }
};

int main()
{
  Solution sol;
  cout << sol.isThree(9) << endl;  // Output: true
  cout << sol.isThree(16) << endl; // Output: false
  return 0;
}
