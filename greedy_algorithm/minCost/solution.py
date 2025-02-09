def minCost(arr, brr, k):
    # Calculate direct modification cost (c1)
    c1 = sum(abs(a - b) for a, b in zip(arr, brr))
    
    # Sort both arrays
    arr_sorted = sorted(arr)
    brr_sorted = sorted(brr)
    
    # Calculate rearrangement and modification cost (c2)
    c2 = k + sum(abs(a - b) for a, b in zip(arr_sorted, brr_sorted))
    
    # Return the minimum of the two costs
    return min(c1, c2)

# Example usage:
arr = [-7, 9, 5]
brr = [7, -2, -5]
k = 2
print(minCost(arr, brr, k))  # Output: 13
