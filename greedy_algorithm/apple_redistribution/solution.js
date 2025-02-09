function minimumBoxes(apple, capacity) {
  let totalApples = apple.reduce((sum, a) => sum + a, 0);
  capacity.sort((a, b) => b - a);
  let boxesUsed = 0;

  for (let cap of capacity) {
    totalApples -= cap;
    boxesUsed++;
    if (totalApples <= 0) return boxesUsed;
  }

  return boxesUsed;
}

// example usgae

console.log(minimumBoxes([1, 3, 2], [4, 3, 1, 5, 2])); // Output: 2

console.log(minimumBoxes([1, 2, 3, 4], [3, 2, 1, 5])); // Output: 3