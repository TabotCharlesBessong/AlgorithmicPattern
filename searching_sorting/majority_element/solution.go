package main

import "fmt"

func majorityElement(nums []int) int {
    counts := make(map[int]int)

    // Count occurrences
    for _, num := range nums {
        counts[num]++
    }

    // Find majority element
    majorityKey := -1
    majorityCount := -1

    for key, value := range counts {
        if value > majorityCount {
            majorityKey = key
            majorityCount = value
        }
    }

    return majorityKey
}

func main() {
    fmt.Println(majorityElement([]int{3, 2, 3}))
    fmt.Println(majorityElement([]int{2, 2, 1, 1, 1, 2, 2}))
}
