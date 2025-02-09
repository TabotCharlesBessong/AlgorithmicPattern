function minCostToEqualizeArray(nums, cost1, cost2) {
  const mod = 1e9 + 7;
  const n = nums.length;
  const maxNum = Math.max(...nums);
  const minNum = Math.min(...nums);
  let maxGap = maxNum - minNum;
  const ttlGap = maxNum * n - nums.reduce((sum, num) => sum + num, 0);

  if (cost1 * 2 <= cost2) {
    return (ttlGap * cost1) % mod;
  }

  if (maxGap * 2 <= ttlGap) {
    let res = Math.floor(ttlGap / 2) * cost2;
    if (ttlGap % 2 === 1) {
      res +=
        n % 2 === 1 ? Math.min(cost1, cost2 * Math.floor((n + 1) / 2)) : cost1;
    }
    return res % mod;
  }

  let res = cost2 * (ttlGap - maxGap);
  maxGap -= ttlGap - maxGap;

  if (maxGap >= n - 1) {
    if (cost2 * (n - 1) >= cost1 * (n - 2)) {
      res += Math.floor(maxGap / (n - 1)) * (n - 1) * cost1;
      maxGap %= n - 1;
    } else {
      res += Math.floor(maxGap / (n - 2)) * (n - 1) * cost2;
      maxGap %= n - 2;
    }
  }

  if (maxGap) {
    let op2 = Math.floor((n + maxGap) / 2) * cost2;
    if ((n + maxGap) % 2 === 1) {
      op2 +=
        n % 2 === 1 ? Math.min(cost1, cost2 * Math.floor((n + 1) / 2)) : cost1;
    }
    res += Math.min(op2, maxGap * cost1);
  }

  return res % mod;
}

// ✅ Test Cases
console.log(minCostToEqualizeArray([1, 1000000], 1000000, 1000000)); // Expected: 998993007
console.log(minCostToEqualizeArray([10, 20, 30], 2, 3)); // Expected: 10
console.log(minCostToEqualizeArray([4, 8, 15, 16, 23, 42], 5, 7)); // Expected: 50
