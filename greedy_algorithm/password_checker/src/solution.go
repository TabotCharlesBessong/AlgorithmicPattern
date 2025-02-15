package main

import (
	"fmt"
	"math"
	"regexp"
	"sort"
	// "strings"
)

// func strongPasswordChecker(s string) int {
// 	lowercase := "abcdefghijklmnopqrstuvwxyz"
// 	uppercase := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// 	digits := "0123456789"

// 	numDeletions := max(0, len(s)-20)

// 	hasLower := strings.ContainsAny(s, lowercase)
// 	hasUpper := strings.ContainsAny(s, uppercase)
// 	hasDigit := strings.ContainsAny(s, digits)
// 	numMissingTypes := boolToInt(!hasLower) + boolToInt(!hasUpper) + boolToInt(!hasDigit)

// 	substringLengths := countSubstringLengths(s)
// 	breakSubstringsWithDeletions(&substringLengths, numDeletions)
// 	numSubstringBreaks := 0
// 	for _, length := range substringLengths {
// 		if length >= 3 {
// 			numSubstringBreaks += length / 3
// 		}
// 	}

// 	numInsertions := max(0, 6-len(s))

// 	max1 := max(numMissingTypes, numInsertions)

// 	// max1 := max(numInsertions, numMissingTypes)

// 	fmt.Println("Number of deletion: ", numDeletions, "Num of insertion: ", numInsertions, "Num of missing types: ", numMissingTypes, "Num of substring break: ", numSubstringBreaks, "First maximum: ", max1, "Substring length: ", substringLengths)

// 	return numDeletions + max(max1, numSubstringBreaks)
// }

func countSubstringLengths(s string) []int {
	result := []int{1}
	lastSeen := s[0]

	for i := 1; i < len(s); i++ {
		if s[i] == lastSeen {
			result[len(result)-1]++
		} else {
			result = append(result, 1)
			lastSeen = s[i]
		}
	}
	return result
}

func breakSubstringsWithDeletions(substringLengths *[]int, numDeletions int) {
	for numDeletions > 0 {
		bestIdx := -1
		minMod := math.Inf(1)

		for i, length := range *substringLengths {
			if length >= 3 && float64(length%3) < minMod {
				bestIdx = i
				minMod = float64(length % 3)
			}
		}

		if bestIdx == -1 {
			break
		}
		(*substringLengths)[bestIdx]--
		numDeletions--
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func strongPasswordChecker(pw string, minLength int, maxLength int, maxRepeat int) int {
	re := regexp.MustCompile(fmt.Sprintf(`(.)\1{0,%d}(?=\1{%d})`, maxRepeat, maxRepeat))
	matches := re.FindAllString(pw, -1)

	changes := make([]int, len(matches))
	for i, match := range matches {
		changes[i] = len(match)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(changes)))

	toRemove := len(pw) - maxLength
	for len(changes) > 0 && changes[len(changes)-1] <= toRemove {
		toRemove -= changes[len(changes)-1]
		changes = changes[:len(changes)-1]
	}

	missingTypes := 0
	if !regexp.MustCompile(`[a-z]`).MatchString(pw) {
		missingTypes++
	}
	if !regexp.MustCompile(`[A-Z]`).MatchString(pw) {
		missingTypes++
	}
	if !regexp.MustCompile(`[0-9]`).MatchString(pw) {
		missingTypes++
	}

	numChanges := max(len(changes), missingTypes)
	return max(minLength-len(pw), numChanges+max(0, len(pw)-maxLength))
}

func main() {
	// fmt.Println(strongPasswordChecker("a"))        // Output: 5
	// fmt.Println(strongPasswordChecker("aaa111"))   // Output: 2
	// fmt.Println(strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA")) // Expected: 23

	fmt.Println(strongPasswordChecker("aaaBBB111", 6, 20, 2))  // Output: 3
	fmt.Println(strongPasswordChecker("AAAAAAAAAAA123", 6, 20, 2))  // Output: 3
}
