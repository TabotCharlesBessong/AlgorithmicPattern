#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
  unordered_map<char, int> freq;
  for (char task : tasks)
  {
    freq[task]++;
  }

  vector<int> counts;
  for (auto it : freq)
  {
    counts.push_back(it.second);
  }

  sort(counts.rbegin(), counts.rend());

  int maxFreq = counts[0];
  int countMaxFreq = count(counts.begin(), counts.end(), maxFreq);

  return max((maxFreq - 1) * (n + 1) + countMaxFreq, (int)tasks.size());
}

int main()
{
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  cout << leastInterval(tasks, n) << endl; // Output: 8
}
