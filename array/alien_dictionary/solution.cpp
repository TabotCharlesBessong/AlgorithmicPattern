#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
  bool isAlienSorted(vector<string> &words, string order)
  {
    unordered_map<char, int> charOrder;

    // Map each character to its order
    for (int i = 0; i < order.size(); ++i)
    {
      charOrder[order[i]] = i;
    }

    // Compare adjacent words
    for (int i = 0; i < words.size() - 1; ++i)
    {
      if (!inCorrectOrder(words[i], words[i + 1], charOrder))
      {
        return false;
      }
    }
    return true;
  }

private:
  bool inCorrectOrder(const string &word1, const string &word2, unordered_map<char, int> &charOrder)
  {
    int minLength = min(word1.size(), word2.size());

    for (int i = 0; i < minLength; ++i)
    {
      if (word1[i] != word2[i])
      {
        return charOrder[word1[i]] < charOrder[word2[i]];
      }
    }

    return word1.size() <= word2.size();
  }
};

int main()
{
  Solution solution;
  vector<string> words = {"hello", "leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";

  if (solution.isAlienSorted(words, order))
  {
    cout << "The words are sorted in the alien dictionary order." << endl;
  }
  else
  {
    cout << "The words are NOT sorted in the alien dictionary order." << endl;
  }

  return 0;
}
