
class Solution:
  def __init__(self):
    self.values = {
      'I': 1,
      'V': 5,
      'X': 10,
      'L': 50,
      'C': 100,
      'D': 500,
      'M': 1000,
      'IV': 4,
      'IX': 9,
      'XL': 40,
      'XC': 90,
      'CD': 400,
      'CM': 900
    }

  def romanToInt(self, s: str) -> int:
    sum = 0
    i = 0

    while i < len(s):
      if i + 1 < len(s):
        doubleSymbol = s[i:i + 2]
        if doubleSymbol in self.values:
          sum += self.values[doubleSymbol]
          i += 2
          continue
      sum += self.values[s[i]]
      i += 1

    return sum
  
# example usage:
solution = Solution()
roman_numeral = "MCMXCIV"
integer_value = solution.romanToInt(roman_numeral)
print(f"The integer value of Roman numeral {roman_numeral} is: {integer_value}")