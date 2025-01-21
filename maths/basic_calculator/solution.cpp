// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int calculate(string s)
// {
//   vector<int> stack;
//   int currentNumber = 0;
//   char operation = '+';
//   s.erase(remove(s.begin(), s.end(), ' '), s.end()); // Remove spaces

//   for (int i = 0; i < s.size(); i++)
//   {
//     char ch = s[i];
//     if (isdigit(ch))
//     {
//       currentNumber = currentNumber * 10 + (ch - '0');
//     }

//     if (!isdigit(ch) || i == s.size() - 1)
//     {
//       if (operation == '+')
//       {
//         stack.push_back(currentNumber);
//       }
//       else if (operation == '-')
//       {
//         stack.push_back(-currentNumber);
//       }
//       else if (operation == '*')
//       {
//         stack.back() *= currentNumber;
//       }
//       else if (operation == '/')
//       {
//         stack.back() /= currentNumber;
//       }

//       operation = ch;
//       currentNumber = 0;
//     }
//   }

//   int result = 0;
//   for (int num : stack)
//   {
//     result += num;
//   }

//   return result;
// }

// int main()
// {
//   cout << calculate("3+2*2") << endl; // Output: 7
//   return 0;
// }
