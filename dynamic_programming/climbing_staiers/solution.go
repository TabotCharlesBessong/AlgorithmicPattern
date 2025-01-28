package main

import "fmt"

func climbStairs(n int) int {
	if n <= 1 {
		return 1
	}

	dp := make([]int, n+1)
	dp[0], dp[1] = 1, 1
	for i := 2; i <= n; i++ {
    dp[i] = dp[i-1] + dp[i-2]
  }

	return dp[n]
}

func main() {
	fmt.Println(climbStairs(2)) // Output: 2
  fmt.Println(climbStairs(3)) // Output: 3
  fmt.Println(climbStairs(4)) // Output: 5
}