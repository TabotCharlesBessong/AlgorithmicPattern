package main

import "fmt"

func min (a int, b int) int {
	if a < b {
    return a
  }
  return b
}

func nthUglyNumber(n int) int {
	dp := make([]int, n)
	dp[0] = 1

	i2, i3, i5 := 0, 0, 0
	for i := 1; i < n; i++ {
		next2, next3, next5 := dp[i2]*2, dp[i3]*3, dp[i5]*5
		dp[i] = min(min(next2, next3), next5)

		if dp[i] == next2{
			i2++
		}
		if dp[i] == next3{
			i3++
		}
		if dp[i] == next5{
			i5++
		}
	}
	return dp[n-1]
}

func main() {
	fmt.Println(nthUglyNumber(10)) // Output: 12
	fmt.Println(nthUglyNumber(17))  // Output: 27
}