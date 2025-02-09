var leastInterval = function (tasks, n) {
  let freq = new Array(26).fill(0);

  for (let task of tasks) {
    // counting the frequency of each task
    freq[task.charCodeAt(0) - "A".charCodeAt(0)]++;
  }

  freq.sort((a, b) => b - a); // Sort in descending order

  let maxFreq = freq[0];
  // getting all the task with the highest frequency
  let countMaxFreq = freq.filter((f) => f === maxFreq).length;

  return Math.max((maxFreq - 1) * (n + 1) + countMaxFreq, tasks.length);
};

// Example Usage:
console.log(leastInterval(["A", "A", "A", "B", "B", "B"], 2)); // Output: 8
