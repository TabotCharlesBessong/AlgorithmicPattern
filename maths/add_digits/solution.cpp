#include <iostream>
using namespace std;

int addDigits(int num)
{
  if (num == 0)
    return 0;
  return 1 + (num - 1) % 9;
}

int main()
{
  int num = 38;
  cout << "Result: " << addDigits(num) << endl; // Output: 2
  return 0;
}
