#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getPermutation(int n, int k)
{
  vector<int> nums;
  int fact = 1;
  for (int i = 1; i <= n; i++)
  {
    nums.push_back(i);
    fact *= i;
  }

  k--; // Convert to zero-based index
  string result = "";
  for (int i = 0; i < n; i++)
  {
    fact /= (n - i);                  // Update factorial
    int index = k / fact;             // Find current index
    result += to_string(nums[index]); // Append number
    nums.erase(nums.begin() + index); // Remove used number
    k %= fact;                        // Update k for next round
  }
  return result;
}

int main()
{
  int n = 4, k = 9;
  cout << "Permutation: " << getPermutation(n, k) << endl;
  return 0;
}
