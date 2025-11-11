
def remove_duplicates(nums):
    if not nums:
        return 0

    write_index = 1

    for read_index in range(1, len(nums)):
        if nums[read_index] != nums[read_index - 1]:
            nums[write_index] = nums[read_index]
            write_index += 1

    return write_index
  
  
# Example
if __name__ == "__main__":
    arr = [1, 1, 2, 3, 3]
    length = remove_duplicates(arr)
    print("Unique elements:", arr[:length])
    print("Count:", length)