var canCompleteCircuit = function (gas, cost) {
  let totalGas = 0,
    totalCost = 0,
    tank = 0,
    start = 0;

  for (let i = 0; i < gas.length; i++) {
    totalGas += gas[i];
    totalCost += cost[i];
    tank += gas[i] - cost[i];

    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }

  return totalGas < totalCost ? -1 : start;
};

// Example usage:
console.log(canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2])); // Output: 3
console.log(
  canCompleteCircuit([1, 2, 3, 4, 5, 4, 1, 1, 1], [3, 4, 5, 1, 2, 1, 2, 10, 8])
); // Output: 9
