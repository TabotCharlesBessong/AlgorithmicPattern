
def peakIndexInMountainArray(arr):
  left = 0
  right = len(arr) - 1
  
  while left < right:
    mid = (left + right) // 2
    
    if arr[mid] < arr[mid + 1]:
      left = mid + 1
    elif arr[mid] > arr[mid + 1]:
      right = mid
      
  return left

if __name__ == '__main__':
  print(peakIndexInMountainArray([0,1,2,4,2,1]))