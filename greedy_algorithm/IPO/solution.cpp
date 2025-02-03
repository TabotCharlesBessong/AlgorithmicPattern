#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital){
  vector<pair<int, int>> projects;
  for (int i = 0; i < profits.size(); i++){
    projects.push_back({capital[i],profits[i]});
  }

  sort(projects.begin(), projects.end());
  priority_queue<int> maxHeap;
  int i = 0, n = projects.size();

  while (k--){
    while(i < n && projects[i].first <= w){
      maxHeap.push(projects[i].second);
      i++;
    }
    if (!maxHeap.empty()){
      w += maxHeap.top();
      maxHeap.pop();
    }else{
      break;
    }
  }
  return w;
};

int main()
{
  vector<int> profits = {1, 2, 3};
  vector<int> capital = {0, 1, 1};
  cout << findMaximizedCapital(2, 0, profits, capital) << endl; // Expected: 4
  return 0;
}