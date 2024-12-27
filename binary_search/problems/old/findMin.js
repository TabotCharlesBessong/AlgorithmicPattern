function findMin(nums) {
  let minVal = nums[0];
  for (let num of nums) {
    if (num < minVal) {
      minVal = num;
    }
  }
  return minVal;
}

const arr = [2, 2, 2, 0, 1];

console.log(findMin(arr))