#include <iostream>
#include <algorithm>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
  int area1 = (C - A) * (D - B);
  int area2 = (G - E) * (H - F);

  int overlapWidht = max(0,min(C,G) - max(A,E));
  int overlapHeight = max(0, min(D, H) - max(B, F));
  int overlapArea = overlapWidht * overlapHeight;

  return area1 + area2 - overlapArea;
}

int main()
{
  cout << computeArea(0, 0, 2, 2, 1, 1, 3, 3) << endl; // Output: 7
  cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl; // Output: 45
  return 0;
}