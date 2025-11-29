#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Solution{
  public:
    string largestNumber(vector<int>& nums){
      vector<string> arr;
      arr.reserve(nums.size());

      for (int n : nums){
        arr.push_back(to_string(n))
      }

      sort(arr.begin(), arr.end(), [](const string& a, const string& b){
        return a + b > b + a;
      })

      if(arr[0] == "0"){
        return "0";
      }

      string result;
      for (const auto& s : arr){
        result += s;
      }
      return result;
    }
}