def canCompleteCircuit(gas,cost):
  totalGas, totalCost, tank, start = 0,0,0,0
  
  for i in range(len(gas)):
    totalGas += gas[i]
    totalCost += cost[i]
    tank += gas[i] - cost[i]
    
    if tank < 0:
      start = i + 1
      tank = 0
      
  return -1 if totalGas < totalCost else start

# example usage
print(canCompleteCircuit([1,2,3,4,5],[3,4,5,1,2]))
print(canCompleteCircuit([1,2,3,4,5,4,1,1,1], [3,4,5,1,2,1,2,10,8])); # Output: 9