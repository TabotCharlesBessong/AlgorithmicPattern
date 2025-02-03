#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// int minCost(vector<int> &arr, vector<int> &brr, int k)
// {
//   int c1 = 0;
//   for (size_t i = 0; i < arr.size(); i++)
//   {
//     c1 += abs(arr[i] - brr[i]);
//   }

//   vector<int> arrSorted = arr;
//   vector<int> brrSorted = brr;
//   sort(arrSorted.begin(), arrSorted.end());
//   sort(brrSorted.begin(), brrSorted.end());

//   int c2 = k;
//   for (size_t i = 0; i < arrSorted.size(); i++)
//   {
//     c2 += abs(arrSorted[i] - brrSorted[i]);
//   }

//   return min(c1, c2);
// }

long long minCost(vector<int>& arr, vector<int>& brr, long long k){
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());

  long long totalCost = 0;
  for (size_t i = 0; i < arr.size(); i++){
    totalCost += abs(arr[i] - brr[i]);
  }

  return totalCost;
}

int main()
{
  vector<int> arr = {-7, 9, 5};
  vector<int> brr = {7, -2, -5};
  int k = 2;
  cout << minCost(arr, brr, k) << endl; // Output: 13

  vector<int> arr2 = {2, 1};
  vector<int> brr2 = {2, 1};
  cout << minCost(arr2, brr2, 0) << endl; // Output: 0

  vector<int> arr3 = {41474, -14784, 13803, -59462, -91436, 695, -91381, 37474, 434, 86033};
  vector<int> brr3 = {38579, -16332, 12615, -57843, -90149, -1513, -90011, 35050, -1971, 89160};
  long long k3 = 2847083024;

  cout << minCost(arr3, brr3, k3) << endl; // Should return 3215064

  return 0;
}
