#include <string>
#include <iostream>

using namespace std;

int maxRepeating(string sequence, string word){
  int k = 0;
  string repeatedWord = word;

  while (sequence.find(repeatedWord) != string::npos){
    k++;
    repeatedWord += word;
  }

  return k;
};

int main(){
  string sequence = "bananaapplebanana";
  string word = "banana";
  cout << "The maximum number of repeating '" << word << "' in the sequence '" << sequence << "' is: " << maxRepeating(sequence, word) << endl;

  cout << maxRepeating("ababc", "ab") << endl; // Output: 2
  cout << maxRepeating("ababc", "ba") << endl; // Output: 1
  cout << maxRepeating("ababc", "ac") << endl; // Output: 0
  return 0;
}