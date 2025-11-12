def longest_common_prefix(strs):
    if not strs:
        return ""
    
    prefix = strs[0]
    for i in range(1, len(strs)):
        while not strs[i].startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""
    return prefix


if __name__ == "__main__":
    print(longest_common_prefix(["flower", "flow", "flight"]))  # Output: "fl"
    print(longest_common_prefix(["dog", "racecar", "car"]))     # Output: ""