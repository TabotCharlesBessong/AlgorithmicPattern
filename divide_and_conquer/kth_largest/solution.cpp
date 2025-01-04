#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k){
      priority_queue<int> pq;
      for (int num : nums){
        pq.push(num);
      }
      k--;
      while(k > 0){
        pq.pop();
        k--;
      }
      return pq.top();
    };
};

int main() {
  vector<int> nums = {7, 10, 4, 3, 20, 15, 8, 6};
  int k = 3;
  Solution solution;
  cout << solution.findKthLargest(nums, k) << endl; // Output: 10
  return 0;
}