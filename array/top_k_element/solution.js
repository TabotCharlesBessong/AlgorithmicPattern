
const topKElement = (nums,k) => {
  if (k === nums.length) return nums

  const count = new Map()
  for (const n of nums){
    // counting the frequency of each number
    count.set(n, (count.get(n) || 0) + 1)
  }

  const heap = []
  const comparator = (a,b) => count.get(a) - count.get(b)

  // building the heap of size k
  for (const n of count.keys()){
    heap.push(n)
    heap.sort(comparator)
    if (heap.length > k) heap.shift()
  }

  return heap
}