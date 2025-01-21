#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string numberToWords(int num)
  {
    if (num == 0)
    {
      return "Zero";
    }

    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string result = "";
    int groupIndex = 0;

    while (num > 0)
    {
      int group = num % 1000;
      if (group != 0)
      {
        result = helper(group, ones, teens, tens) + (thousands[groupIndex].empty() ? "" : " " + thousands[groupIndex]) + " " + result;
      }
      num /= 1000;
      groupIndex++;
    }

    // Trim trailing spaces
    result.erase(result.find_last_not_of(" ") + 1);
    return result;
  }

private:
  string helper(int num, const vector<string> &ones, const vector<string> &teens, const vector<string> &tens)
  {
    string result = "";
    if (num >= 100)
    {
      result += ones[num / 100] + " Hundred ";
      num %= 100;
    }
    if (num >= 20)
    {
      result += tens[num / 10] + " ";
      num %= 10;
    }
    if (num >= 10 && num < 20)
    {
      result += teens[num - 10] + " ";
      return result;
    }
    if (num > 0)
    {
      result += ones[num] + " ";
    }
    return result;
  }
};

int main()
{
  Solution solution;
  cout << solution.numberToWords(12345) << endl;   // Output: "Twelve Thousand Three Hundred Forty Five"
  cout << solution.numberToWords(1234567) << endl; // Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
  cout << solution.numberToWords(10) << endl;      // Output: "Ten"
  cout << solution.numberToWords(0) << endl;       // Output: "Zero"
  return 0;
}
