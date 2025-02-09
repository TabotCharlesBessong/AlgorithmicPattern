const minCost = (arr,brr,k) => {
  let c1 = arr.reduce((sum,a,i) => sum + Math.abs(a - brr[i]),0)

  let arrSorted = [...arr].sort((a,b) =>a - b)
  let brrSorted = [...brr].sort((a,b) =>a - b)

  let c2 = k + arrSorted.reduce((sum,a,i) => sum + Math.abs(a - brrSorted[i]),0)

  return Math.min(c1,c2)
}

// Example Usage
console.log(minCost([-7, 9, 5], [7, -2, -5], 2)); // Output: 13
console.log(minCost([2, 1], [2, 1], 0));         // Output: 0