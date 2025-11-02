#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k)
{
  vector<int> occurrence(26, 0);
  int left = 0, ans = 0, maxOccurrence = 0;

  for (int right = 0; right < s.size(); right++)
  {
    int index = s[right] - 'A';
    occurrence[index]++;
    maxOccurrence = max(maxOccurrence, occurrence[index]);

    if (right - left + 1 - maxOccurrence > k)
    {
      occurrence[s[left] - 'A']--;
      left++;
    }
    else
    {
      ans = max(ans, right - left + 1);
    }
  }

  return ans;
}

int main()
{
  cout << characterReplacement("AABABBA", 1) << endl; // Output: 4
  return 0;
}
