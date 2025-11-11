#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
  int left = 0, right = s.size() - 1;

  while (left < right)
  {
    if (!isalnum(s[left]))
    {
      left++;
    }
    else if (!isalnum(s[right]))
    {
      right--;
    }
    else
    {
      if (tolower(s[left]) != tolower(s[right]))
      {
        return false;
      }
      left++;
      right--;
    }
  }
  return true;
}

int main()
{
  cout << boolalpha << isPalindrome("A man, a plan, a canal: Panama") << endl; // true
  cout << boolalpha << isPalindrome("race a car") << endl;                     // false
  return 0;
}
