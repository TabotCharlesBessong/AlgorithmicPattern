#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    /**
     * BRUTE FORCE SOLUTION
     * 
     * @param nums Vector of integers
     * @return First missing positive integer
     * 
     * Time Complexity: O(n²)
     * Space Complexity: O(1)
     */
    int firstMissingPositiveBruteForce(std::vector<int>& nums) {
        int candidate = 1;
        
        while (true) {
            // Check if candidate exists in array
            bool found = false;
            for (int num : nums) {
                if (num == candidate) {
                    found = true;
                    break;
                }
            }
            
            // If candidate not found, it's our answer
            if (!found) {
                return candidate;
            }
            
            candidate++;
        }
    }
    
    /**
     * OPTIMAL SOLUTION - Index as Hash Map
     * 
     * @param nums Vector of integers
     * @return First missing positive integer
     * 
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Check if 1 exists in array
        bool contains1 = false;
        for (int num : nums) {
            if (num == 1) {
                contains1 = true;
                break;
            }
        }
        
        // If 1 is not present, return 1
        if (!contains1) {
            return 1;
        }
        
        // Step 2: Replace numbers <= 0 or > n with 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        
        // Step 3: Use array indices as hash map
        // Mark presence of number x by making nums[x-1] negative
        for (int i = 0; i < n; i++) {
            int num = std::abs(nums[i]);
            if (num == n) {
                nums[0] = -std::abs(nums[0]);
            } else {
                nums[num] = -std::abs(nums[num]);
            }
        }
        
        // Step 4: Find first positive number (missing positive)
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }
        
        // Check if n is missing
        if (nums[0] > 0) {
            return n;
        }
        
        // All numbers 1 to n are present
        return n + 1;
    }
};

// Helper function to create a copy of vector for testing
std::vector<int> copyVector(const std::vector<int>& original) {
    return std::vector<int>(original);
}

int main() {
    Solution solution;
    
    std::cout << "=== First Missing Positive - Test Cases ===" << std::endl;
    
    // Test cases
    std::vector<std::vector<int>> testCases = {
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
        {},
        {1},
        {2},
        {-1, -2, -3},
        {1, 2, 3, 4, 5}
    };
    
    std::vector<int> expected = {3, 2, 1, 1, 2, 1, 1, 6};
    
    // Test Brute Force
    std::cout << "Brute Force Results:" << std::endl;
    for (int i = 0; i < testCases.size(); i++) {
        auto testCopy = copyVector(testCases[i]);
        int result = solution.firstMissingPositiveBruteForce(testCopy);
        std::cout << "Test " << (i + 1) << ": ";
        std::cout << "{ ";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j < testCases[i].size() - 1) std::cout << ", ";
        }
        std::cout << " } -> " << result << " (expected: " << expected[i] << ")" << std::endl;
    }
    
    // Test Optimal
    std::cout << "\nOptimal Solution Results:" << std::endl;
    for (int i = 0; i < testCases.size(); i++) {
        auto testCopy = copyVector(testCases[i]);
        int result = solution.firstMissingPositive(testCopy);
        std::cout << "Test " << (i + 1) << ": ";
        std::cout << "{ ";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j < testCases[i].size() - 1) std::cout << ", ";
        }
        std::cout << " } -> " << result << " (expected: " << expected[i] << ")" << std::endl;
    }
    
    return 0;
}