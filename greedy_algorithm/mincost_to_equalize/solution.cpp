#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long minCostToEqualizeArray(vector<int> &nums, int cost1, int cost2)
{
  long long mod = 1e9 + 7;
  int n = nums.size();
  int maxNum = *max_element(nums.begin(), nums.end());
  int minNum = *min_element(nums.begin(), nums.end());
  int maxGap = maxNum - minNum;
  long long ttlGap = (long long)maxNum * n - accumulate(nums.begin(), nums.end(), 0LL);

  if (cost1 * 2 <= cost2)
    return (ttlGap * cost1) % mod;

  if (maxGap * 2 <= ttlGap)
  {
    long long res = (ttlGap / 2) * cost2;
    if (ttlGap % 2 == 1)
    {
      res += (n % 2 == 1) ? min(cost1, cost2 * (n + 1) / 2) : cost1;
    }
    return res % mod;
  }

  long long res = cost2 * (ttlGap - maxGap);
  maxGap -= (ttlGap - maxGap);

  if (maxGap >= n - 1)
  {
    if (cost2 * (n - 1) >= cost1 * (n - 2))
    {
      res += (maxGap / (n - 1)) * (n - 1) * cost1;
      maxGap %= (n - 1);
    }
    else
    {
      res += (maxGap / (n - 2)) * (n - 1) * cost2;
      maxGap %= (n - 2);
    }
  }

  if (maxGap)
  {
    long long op2 = ((n + maxGap) / 2) * cost2;
    if ((n + maxGap) % 2 == 1)
    {
      op2 += (n % 2 == 1) ? min(cost1, cost2 * (n + 1) / 2) : cost1;
    }
    res += min(op2, maxGap * cost1);
  }

  return res % mod;
}

// ✅ Test Cases
int main()
{
  vector<int> nums1 = {1, 1000000};
  cout << minCostToEqualizeArray(nums1, 1000000, 1000000) << endl; // Expected: 998993007

  vector<int> nums2 = {10, 20, 30};
  cout << minCostToEqualizeArray(nums2, 2, 3) << endl; // Expected: 10

  vector<int> nums3 = {4, 8, 15, 16, 23, 42};
  cout << minCostToEqualizeArray(nums3, 5, 7) << endl; // Expected: 50
}
