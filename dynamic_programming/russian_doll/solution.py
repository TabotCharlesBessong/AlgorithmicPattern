from bisect import bisect_left

def maxEnvelopes(envelopes):
  if not envelopes:
    return 0
  
  # step 1: sort the envelopes
  envelopes.sort(key=lambda x: (x[0], -x[1]))
  
  # step 2: extract heights and apply LIS
  heights = [h for _, h in envelopes]
  dp = []
  
  for h in heights:
    pos = bisect_left(dp,h)
    if pos == len(dp):
      dp.append(h)
    
    else:
      dp[pos] = h
      
  return len(dp)

print(maxEnvelopes([[5,4],[6,4],[6,7],[2,3],[1,1]]))