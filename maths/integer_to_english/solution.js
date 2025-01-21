var numberToWords = function (num) {
  if (num === 0) return "Zero";

  const ones = [
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
  ];
  const teens = [
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
  ];
  const tens = [
    "",
    "Ten",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety",
  ];
  const thousands = ["", "Thousand", "Million", "Billion"];

  const convertToWords = (num) => {
    let result = "";
    if (num >= 100) {
      result += ones[Math.floor(num / 100)] + " Hundred ";
      num %= 100;
    }
    if (num >= 20) {
      result += tens[Math.floor(num / 10)] + " ";
      num %= 10;
    }
    if (num >= 10 && num < 20) {
      result += teens[num - 10] + " ";
    } else if (num > 0) {
      result += ones[num] + " ";
    }
    return result.trim();
  };

  let result = "";
  let groupIndex = 0;

  while (num > 0) {
    const group = num % 1000;
    if (group > 0) {
      let groupWords = convertToWords(group);
      if (thousands[groupIndex]) {
        groupWords += " " + thousands[groupIndex];
      }
      result = groupWords + " " + result;
    }
    num = Math.floor(num / 1000);
    groupIndex++;
  }

  return result.trim();
};

// Test cases
console.log(numberToWords(1234567)); // Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
console.log(numberToWords(1000)); // Output: "One Thousand"
console.log(numberToWords(1000000)); // Output: "One Million"
