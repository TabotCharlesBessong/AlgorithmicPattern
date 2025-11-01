/**
 * First Missing Positive - LeetCode 41
 * 
 * Brute Force Approach: Check each positive integer starting from 1
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

/**
 * BRUTE FORCE SOLUTION
 * @param {number[]} nums
 * @return {number}
 */
function firstMissingPositiveBruteForce(nums) {
    // Start checking from 1
    let candidate = 1;
    
    while (true) {
        let found = false;
        
        // Check if candidate exists in array
        for (let i = 0; i < nums.length; i++) {
            if (nums[i] === candidate) {
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
 * @param {number[]} nums
 * @return {number}
 */
function firstMissingPositive(nums) {
    const n = nums.length;
    
    // Step 1: Check if 1 exists in array
    let contains1 = false;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            contains1 = true;
            break;
        }
    }
    
    // If 1 is not present, return 1
    if (!contains1) {
        return 1;
    }
    
    // Step 2: Replace numbers <= 0 or > n with 1
    for (let i = 0; i < n; i++) {
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1;
        }
    }
    
    // Step 3: Use array indices as hash map
    // Mark presence of number x by making nums[x-1] negative
    for (let i = 0; i < n; i++) {
        const num = Math.abs(nums[i]);
        if (num === n) {
            nums[0] = -Math.abs(nums[0]);
        } else {
            nums[num] = -Math.abs(nums[num]);
        }
    }
    
    // Step 4: Find first positive number (missing positive)
    for (let i = 1; i < n; i++) {
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

// Test cases
console.log("=== First Missing Positive - Test Cases ===");

// Test Brute Force
console.log("Brute Force Results:");
console.log("Test 1:", firstMissingPositiveBruteForce([1, 2, 0])); // Expected: 3
console.log("Test 2:", firstMissingPositiveBruteForce([3, 4, -1, 1])); // Expected: 2
console.log("Test 3:", firstMissingPositiveBruteForce([7, 8, 9, 11, 12])); // Expected: 1

// Test Optimal
console.log("\nOptimal Solution Results:");
console.log("Test 1:", firstMissingPositive([1, 2, 0])); // Expected: 3
console.log("Test 2:", firstMissingPositive([3, 4, -1, 1])); // Expected: 2
console.log("Test 3:", firstMissingPositive([7, 8, 9, 11, 12])); // Expected: 1

module.exports = { firstMissingPositive, firstMissingPositiveBruteForce };