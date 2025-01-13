package maths.power;

class Solution {
    public double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return power(x, n);
    }

    private double power(double x, int n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        return (n % 2 == 0) ? half * half : half * half * x;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.myPow(2.0, 10)); // Output: 1024
        System.out.println(solution.myPow(2.0, -2)); // Output: 0.25
    }
}
