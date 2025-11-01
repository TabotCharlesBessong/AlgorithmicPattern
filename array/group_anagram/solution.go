package main

import (
	"fmt"
	"strings"
)

type Solution struct{}

func (s Solution) groupAnagrams(strs []string) [][]string {
	if len(strs) == 0 {
		return [][]string{}
	}

	ans := make(map[string][]string)

	for _, str := range strs {
		count := make([]int, 26)
		for _, c := range str {
			count[c-'a']++
		}
		keyParts := make([]string, 26)
		for i := range count {
			keyParts[i] = fmt.Sprintf("%d", count[i])
		}
		key := strings.Join(keyParts, "#")
		ans[key] = append(ans[key], str)
	}

	result := [][]string{}
	for _, v := range ans {
		result = append(result, v)
	}
	return result
}

func main() {
	sol := Solution{}
	input := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	fmt.Println(sol.groupAnagrams(input))
	// Output: [[eat tea ate] [tan nat] [bat]]
}
