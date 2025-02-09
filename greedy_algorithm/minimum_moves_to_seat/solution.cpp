#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
  sort(seats.begin(), seats.end());
  sort(students.begin(), students.end());

  int moves = 0;
  for (int i = 0; i < seats.size(); i++)
  {
    moves += abs(seats[i] - students[i]);
  }
  return moves;
}

int main()
{
  vector<int> seats = {3, 1, 5};
  vector<int> students = {2, 7, 4};
  cout << minMovesToSeat(seats, students) << endl; // Output: 4
  return 0;
}
