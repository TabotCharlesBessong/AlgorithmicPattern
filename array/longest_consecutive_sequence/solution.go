package main

func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	numSet := make(map[int]bool)
	for _, num := range nums {
		numSet[num] = true
	}

	longestSub := 1
	for num := range numSet {
		if numSet[num-1] {
			continue
		}

		currentNum := num
		currentSub := 1
		for numSet[currentNum+1] {
			currentNum++
			currentSub++
		}

		if currentSub > longestSub {
			longestSub = currentSub
		}
	}

	return longestSub
}
