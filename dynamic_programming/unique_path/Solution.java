public class Solution {
    public static int uniquePaths(int m, int n) {
        int totalSteps = m + n - 2;
        int chooseSteps = Math.min(m - 1, n - 1);
        
        long result = 1; // Use long to handle larger intermediate values
        for (int i = 1; i <= chooseSteps; i++) {
            result *= totalSteps--;
            result /= i; // Integer division
        }
        return (int) result; // Cast back to int for the final result
    }

    public static void main(String[] args) {
        System.out.println(uniquePaths(3, 7)); // Output: 28
        System.out.println(uniquePaths(3, 2)); // Output: 3
        System.out.println(uniquePaths(10, 10)); // Output: 48620
    }
}
