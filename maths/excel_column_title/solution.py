def convertToTitle(n: int) -> str:
  result = []
  while n > 0:
    n -= 1
    remainder = n % 26
    result.append(chr(ord('A') + remainder))
    n //= 26
  return ''.join(reversed(result))


# Example usage:

print(convertToTitle(1))  # Output: 'A'
print(convertToTitle(28))  # Output: 'AB'
print(convertToTitle(701))  # Output: 'ZY'

print(convertToTitle(702))  # Output: 'ZZ'