class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        teens = ["Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        thousands = ["", "Thousand", "Million", "Billion"]

        def convert_to_words(num):
            result = ""
            if num >= 100:
                result += ones[num // 100] + " Hundred "
                num %= 100
            if 20 <= num < 100:
                result += tens[num // 10] + " "
                num %= 10
            if 10 <= num < 20:
                result += teens[num - 10] + " "
            elif num > 0:
                result += ones[num] + " "
            return result.strip()

        result = ""
        group_index = 0

        while num > 0:
            group = num % 1000
            if group > 0:
                group_words = convert_to_words(group)
                if thousands[group_index]:
                    group_words += " " + thousands[group_index]
                result = group_words + " " + result
            num //= 1000
            group_index += 1

        return result.strip()


# Test cases
sol = Solution()
print(sol.numberToWords(1234567))  # Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
print(sol.numberToWords(1000))    # Output: "One Thousand"
print(sol.numberToWords(10000))    # Output: "Ten Thousand"
print(sol.numberToWords(1000000)) # Output: "One Million"
