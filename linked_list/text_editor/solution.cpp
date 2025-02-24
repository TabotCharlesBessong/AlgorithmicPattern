#include <string>
#include <stack>
using namespace std;

class TextEditor
{
public:
  stack<char> leftStack, rightStack;

  TextEditor() {}

  void addText(string text)
  {
    for (char ch : text)
    {
      leftStack.push(ch);
    }
  }

  int deleteText(int k)
  {
    int count = 0;
    while (k > 0 && !leftStack.empty())
    {
      leftStack.pop();
      k--;
      count++;
    }
    return count;
  }

  string cursorLeft(int k)
  {
    while (k > 0 && !leftStack.empty())
    {
      rightStack.push(leftStack.top());
      leftStack.pop();
      k--;
    }
    return getLast10();
  }

  string cursorRight(int k)
  {
    while (k > 0 && !rightStack.empty())
    {
      leftStack.push(rightStack.top());
      rightStack.pop();
      k--;
    }
    return getLast10();
  }

  string getLast10()
  {
    string result;
    stack<char> temp = leftStack;
    while (!temp.empty() && result.size() < 10)
    {
      result = temp.top() + result;
      temp.pop();
    }
    return result;
  }
};