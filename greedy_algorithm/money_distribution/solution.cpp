#include <iostream>

using namespace std;

int maxChildrenWithEightDollars(int n, int m){
  if (n < m) return -1;
  int remainingMoney = n - m;
  int count = min(remainingMoney/ 7,m);

  remainingMoney -= count * 7;
  m -= count;

  if ((m == 0 && remainingMoney > 0) || (m == 1 && remainingMoney == 3) ){
    count--;
  }

  return count;
};

int main()
{
  cout << maxChildrenWithEightDollars(20, 3) << endl; // Output: 1
  cout << maxChildrenWithEightDollars(16, 2) << endl; // Output: 2
  cout << maxChildrenWithEightDollars(2, 2) << endl;  // Output: 0
  return 0;
}