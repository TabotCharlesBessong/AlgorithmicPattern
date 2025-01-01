const findMinimumX = (nums1, nums2) => {
  nums1.sort((a, b) => a - b)
  nums2.sort((a, b) => a - b)
  let minX = Infinity
  for (let i = 0; i < 3; i++){
    const x = nums2[0] - nums1[i]
    if(isValidX(nums1,nums2,x)){
      minX = Math.min(minX, x)
    }
  }
  return minX === Infinity? -1 : minX
}

const isValidX = (nums1, nums2,x) => {
  let removedCount = 0
  let j = 0
  for (let i = 0; i < nums1.length; i++) {
    if(j < nums2.length && nums1[i] + x === nums2[j]) {
      j++
    }else{
      removedCount++
    }
    if(removedCount > 2) return false
  }
  return true
}

console.log(findMinimumX([4, 20, 16, 12,10 , 8], [14, 18, 10,8])); // Output: -2
console.log(findMinimumX([3, 5, 5, 3], [7, 7])); // Output: 2