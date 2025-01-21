#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPrimes(int n)
{
  if (n <= 2)
    return 0;

  vector<bool> isPrime(n, true);
  isPrime[0] = isPrime[1] = false;

  for (int p = 2; p * p < n; ++p)
  {
    if (isPrime[p])
    {
      for (int i = p * p; i < n; i += p)
      {
        isPrime[i] = false;
      }
    }
  }

  return count(isPrime.begin(), isPrime.end(), true);
}

int main()
{
  int n1 = 4, n2 = 70;
  cout << "Number of primes less than " << n1 << ": " << countPrimes(n1) << endl;
  cout << "Number of primes less than " << n2 << ": " << countPrimes(n2) << endl;
  return 0;
}
