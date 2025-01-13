const topKFrequent = (nums,k) => {
  let frequencyMap = new Map()

  // count the frequencies
  for (let num of nums){
    frequencyMap.set(num,(frequencyMap.get(num) || 0) + 1)
  }

  // bucket sort based on frequency
  let bucket = Array(nums.length + 1).fill().map(() => [])
  for (let [num,freq] of frequencyMap.entries()){
    bucket[freq].push(num)
  }

  // extract top k frequent elements
  let result = []
  for (let i = bucket.length - 1; i >= 0 && result.length < k; i--){
    for (let num of bucket[i]){
      result.push(num)
      if (result.length === k) break
    }
  }
  return result
}

console.log(topKFrequent([1, 2, 3, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7, 7, 7],3));