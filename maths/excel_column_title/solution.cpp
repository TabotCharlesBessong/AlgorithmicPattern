#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string convertToTitle(int n)
{
  string result = "";
  while (n > 0)
  {
    n--;
    result += char(n % 26 + 'A');
    n /= 26;
  }
  reverse(result.begin(), result.end());
  return result;
}

int main()
{
  int n = 28;
  string title = convertToTitle(n);
  cout << title << endl; // Output: "AB"
  return 0;
}
