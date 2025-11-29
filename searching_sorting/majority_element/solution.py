
def majorityElement(nums):
  counts = {}
  
  for num in nums:
    counts[num] = counts.get(num, 0) + 1
    
  
  # find the element with the maximum count
  majority_key = None
  for key, count in counts.items():
    if majority_key is None or count > counts[majority_key]:
      majority_key = key
  return majority_key