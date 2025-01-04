#include <iostream>
#include <vector>
using namespace std;

vector<int> beautifulArray(int n)
{
  if (n == 1)
    return {1};

  vector<int> odd = beautifulArray((n + 1) / 2); // Solve for odd indices
  vector<int> even = beautifulArray(n / 2);      // Solve for even indices

  vector<int> result;
  for (int x : odd)
    result.push_back(2 * x - 1); // Map odd group
  for (int x : even)
    result.push_back(2 * x); // Map even group

  return result;
}

int main()
{
  int n;
  // cout << "Enter the number of elements: ";  // Example: 5
  // cin >> n;
  vector<int> result = beautifulArray(5);
  for (int x : result)
    cout << x << " ";
  cout << endl; // Output: [1, 5, 3, 2, 4]
}
