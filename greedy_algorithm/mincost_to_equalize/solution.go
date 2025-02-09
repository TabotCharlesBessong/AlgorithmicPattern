package main

import (
	"fmt"
	// "math"
)

const MOD int64 = 1_000_000_007

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func minCostToEqualizeArray(nums []int, cost1 int64, cost2 int64) int64 {
	n := int64(len(nums))
	mx := int64(nums[0])
	mn := int64(nums[0])

	// find the max and miimum values in nums
	var sum int64 = 0
	for _, num := range nums {
		if int64(num) > mx {
			mx = int64(num)
		}
		if int64(num) < mn {
			mn = int64(num)
		}
		sum += int64(num)
	}

	maxGap := mx - mn
	ttlGap := mx*n - sum

	// case 1: if cost1 * 2 is cheaper than cost2, use only cost1
	if cost1*2 <= cost2 {
		return (ttlGap * cost1) % MOD
	}

	// case 2: if maxGap * 2 <= ttlGap, we can pair up and use cost2 effectively
	if maxGap*2 <= ttlGap {
		res := (ttlGap / 2) * cost2
		if ttlGap%2 == 1 {
			if n%2 == 1 {
				res += min(cost1, cost2*(n+1)/2)
			} else {
				res += cost1
			}
		}
		return res % MOD
	}

	// case 3: Use a mix of cost1 and cost2
	res := cost2 * (ttlGap - maxGap)
	maxGap -= (ttlGap - maxGap)

	if maxGap >= n-1 {
		if cost2*(n-1) >= cost1*(n-2) {
			res += (maxGap / (n - 1)) * (n - 1) * cost1
			maxGap %= (n - 1)
		} else {
			res += (maxGap / (n - 2)) * (n - 1) * cost2
			maxGap %= (n - 2)
		}
	}

	if maxGap > 0 {
		op2 := ((n + maxGap) / 2) * cost2
		if (n+maxGap)%2 == 1 {
			if n%2 == 1 {
				op2 += min(cost1, cost2*(n+1)/2)
			} else {
				op2 += cost1
			}
		}
		res += min(op2, maxGap*cost1)
	}
	return res % MOD
}

// ✅ Example Test Cases
func main() {
	fmt.Println(minCostToEqualizeArray([]int{1, 1000000}, 1000000, 1000000)) // Expected: 998993007
	fmt.Println(minCostToEqualizeArray([]int{10, 20, 30}, 2, 3))             // Expected: 10
	fmt.Println(minCostToEqualizeArray([]int{4, 8, 15, 16, 23, 42}, 5, 7))   // Expected: 50
}
