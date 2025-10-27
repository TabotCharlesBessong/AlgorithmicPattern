
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums){
      unordered_set<int> seenNumbers;
      for (int num : nums){
        if (seenNumbers.count(num)){
          return true;
        } else {
          seenNumbers.insert(num);
        }
      }
      return false;
    }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 1};
  bool result = solution.containsDuplicate(nums);
  cout << (result ? "Contains duplicates" : "No duplicates") << endl;
  return 0;
}