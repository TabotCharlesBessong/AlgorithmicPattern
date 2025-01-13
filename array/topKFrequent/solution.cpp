#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k){
  unordered_map<int, int> frequencyMap;

  // step 1: count frequencies
  for (int num : nums){
    frequencyMap[num]++;
  }

  // step 2: bucket sort
  vector<vector<int>> bucket(nums.size() + 1);
  for (auto& [num, freq] : frequencyMap){
    bucket[freq].push_back(num);
  }

  // step 3: extract top k elements
  vector<int> result;
  for (int i = bucket.size() - 1; i >= 0 && result.size() < k; --i){
    for (int num : bucket[i]){
      result.push_back(num);
      if (result.size() == k) break;
    }
  }
  return result;
}

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> result = topKFrequent(nums, k);
  cout << "Top K Frequent Elements: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}