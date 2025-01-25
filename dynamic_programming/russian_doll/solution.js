
const binarySearch = (dp,target) => {
  let low = 0, high = dp.length;
  while(low <= high) {
    const mid = Math.floor((low + high) / 2);
    if(dp[mid] < target) low = mid + 1
    else high = mid
  }
  return low
}

const maxEnvelopes = (envelopes) => {
  if(envelopes.length === 0) return 0;

  // step 1: sort envelopes
  envelopes.sort((a,b) => a[0] === b[0] ? b[1] - a[1] : a[0] - b[0])

  // step 2: extract heights and apply LIS
  const heights = envelopes.map(e => e[1])
  const dp = []

  for (const h of heights){
    let pos = binarySearch(dp,h)
    if (pos === dp.length) dp.push(h)
    else dp[pos] = h
  }

  return dp.length
}

console.log(
  maxEnvelopes([
    [5, 4],
    [6, 4],
    [6, 7],
    [2, 3],
    [1, 1],
  ])
);

console.log(
  maxEnvelopes([
    [5, 4],
    [6, 4],
    [6, 7],
    [2, 3],
  ])
);