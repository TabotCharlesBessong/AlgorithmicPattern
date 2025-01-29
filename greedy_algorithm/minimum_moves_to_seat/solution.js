const minMovesToSeat = (seats,students) => {
  seats.sort((a, b) => a - b);
  students.sort((a, b) => a - b);

  let moves = 0
  for (let i = 0; i < seats.length; i++) {
    moves += Math.abs(seats[i] - students[i])
  }
  return moves
}

// example usage

console.log(minMovesToSeat([4, 3, 2, 1], [4, 3, 2, 1])) // 0
console.log(minMovesToSeat([4, 3, 2, 1], [5, 4, 3, 2])) // 4
console.log(minMovesToSeat([4, 3, 2, 1], [3, 2, 1, 0])) // 4
console.log(minMovesToSeat([3, 1, 5], [2, 7, 4]))  // Output: 4

// time complexity: O(n log n) due to sorting operations