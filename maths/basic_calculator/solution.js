var calculate = function (s) {
  let stack = [];
  let currentNumber = 0;
  let operation = "+";
  s = s.replace(/\s+/g, ""); // Remove spaces

  for (let i = 0; i < s.length; i++) {
    let char = s[i];

    if (!isNaN(char)) {
      currentNumber = currentNumber * 10 + parseInt(char, 10);
    }

    if (isNaN(char) || i === s.length - 1) {
      if (operation === "+") {
        stack.push(currentNumber);
      } else if (operation === "-") {
        stack.push(-currentNumber);
      } else if (operation === "*") {
        stack.push(stack.pop() * currentNumber);
      } else if (operation === "/") {
        stack.push(Math.trunc(stack.pop() / currentNumber)); // Truncate towards zero
      }

      operation = char;
      currentNumber = 0;
    }
  }

  return stack.reduce((a, b) => a + b, 0);
};

console.log(calculate("3 + 2 * 2"))  // Output: 7
console.log(calculate("14-3/2"))  // Output: 12.5
console.log(calculate(" 3+5 / 2 "));  // Output: 5
