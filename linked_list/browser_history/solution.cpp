#include <string>

#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
  string url;
  ListNode *prev, *next;
  ListNode(string url) : url(url), prev(nullptr), next(nullptr) {}
};

class BrowserHistory
{
public:
  ListNode *current;

  BrowserHistory(string homepage)
  {
    current = new ListNode(homepage);
  }

  void visit(string url)
  {
    ListNode *newNode = new ListNode(url);
    current->next = newNode;
    newNode->prev = current;
    current = newNode;
  }

  string back(int steps)
  {
    while (steps > 0 && current->prev)
    {
      current = current->prev;
      steps--;
    }
    return current->url;
  }

  string forward(int steps)
  {
    while (steps > 0 && current->next)
    {
      current = current->next;
      steps--;
    }
    return current->url;
  }
};

int main(){
  BrowserHistory browser("leetcode.com");
  browser.visit("google.com");
  browser.visit("facebook.com");
  cout << browser.back(1) << endl; // Output: facebook.com
  cout << browser.forward(1) << endl; // Output: google.com
  browser.visit("youtube.com");
  cout << browser.current->url << endl; // Output: youtube.com
  cout << browser.back(2) << endl; // Output: facebook.com
  cout << browser.forward(1) << endl; // Output: youtube.com
}