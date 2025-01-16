import java.util.Arrays;

public class CountPrimes {
  public static int countPrimes(int n) {
    if (n <= 2)
      return 0;

    boolean[] isPrime = new boolean[n];
    Arrays.fill(isPrime, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p < n; p++) {
      if (isPrime[p]) {
        for (int i = p * p; i < n; i += p) {
          isPrime[i] = false;
        }
      }
    }

    int count = 0;
    for (boolean prime : isPrime) {
      if (prime)
        count++;
    }
    return count;
  }

  public static void main(String[] args) {
    int n1 = 4, n2 = 70;
    System.out.println("Number of primes less than " + n1 + ": " + countPrimes(n1));
    System.out.println("Number of primes less than " + n2 + ": " + countPrimes(n2));
  }
}
