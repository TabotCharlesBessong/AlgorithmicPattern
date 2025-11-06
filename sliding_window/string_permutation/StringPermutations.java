/*
Algorithmic Pattern: Backtracking
Problem: Generate all permutations of a string

Description:
Given a string, generate all possible permutations of its characters using 
the backtracking algorithmic pattern.

Example:
Input: "abc"
Output: [abc, acb, bac, bca, cab, cba]
*/

import java.util.ArrayList;
import java.util.List;

public class StringPermutations {

    public static List<String> findPermutations(String s) {
        List<String> result = new ArrayList<>();
        boolean[] used = new boolean[s.length()];
        backtrack(s.toCharArray(), new StringBuilder(), used, result);
        return result;
    }

    private static void backtrack(char[] chars, StringBuilder current, boolean[] used, List<String> result) {
        if (current.length() == chars.length) {
            result.add(current.toString());
            return;
        }

        for (int i = 0; i < chars.length; i++) {
            if (used[i]) continue;
            
            used[i] = true;
            current.append(chars[i]);
            backtrack(chars, current, used, result);
            current.deleteCharAt(current.length() - 1);
            used[i] = false;
        }
    }

    public static void main(String[] args) {
        String input = "abc";
        List<String> permutations = findPermutations(input);

        System.out.println("Permutations of '" + input + "':");
        for (String perm : permutations) {
            System.out.println(perm);
        }
    }
}
