package main

import "fmt"

func topKFrequent(nums []int, k int) []int {
	// set the frequency count
	frequencyMap := make(map[int]int)
	for _, num := range nums {
		frequencyMap[num]++
	}

	// step 2: bucket sort
	buckets := make([][]int, len(nums)+1)
	for num, freq := range frequencyMap {
		buckets[freq] = append(buckets[freq],num)
	}

	// step 3: extract top k frequent elements
	result := []int{}
	for i := len(buckets) - 1; i >= 0 && len(result) < k; i--{
		if buckets[i] != nil {
			result = append(result,buckets[i]...)
		}
	}
	return result[:k]
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := 2
	fmt.Println("Top K Frequent Elements:", topKFrequent(nums, k))
}