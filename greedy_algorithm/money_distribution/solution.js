var maxChildrenWithEightDollars = function (n, m) {
  if (n < m) return -1; // Not enough money to give each child at least $1
  let remainingMoney = n - m; // Money left after giving each child $1
  let count = Math.min(Math.floor(remainingMoney / 7), m); // Maximum children getting exactly $8

  remainingMoney -= count * 7;
  m -= count;

  if ((m === 0 && remainingMoney > 0) || (m === 1 && remainingMoney === 3)) {
    count--;
  }

  return count;
};

// Example Test Cases
console.log(maxChildrenWithEightDollars(20, 3)); // Output: 1
console.log(maxChildrenWithEightDollars(16, 2)); // Output: 2
console.log(maxChildrenWithEightDollars(2, 2)); // Output: 0
