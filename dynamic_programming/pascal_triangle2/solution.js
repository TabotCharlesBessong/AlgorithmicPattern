var getRow = function (rowIndex) {
  let row = [1];
  for (let i = 1; i <= rowIndex; i++) {
    row.push(1); // Add a new 1 at the end
    for (let j = i - 1; j > 0; j--) {
      row[j] = row[j] + row[j - 1];
    }
  }
  return row;
};

// Example Usage
console.log(getRow(4)); // Output: [1, 4, 6, 4, 1]

console.log(getRow(5)); // Output: [1, 5, 10, 10, 5, 1]

