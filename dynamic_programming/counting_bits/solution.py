def countBits(n:int) -> list[int]:
  result = [0] * (n + 1)
  for i in range(1, n + 1):
    result[i] = result[i >> 1] + (i & 1)
  return result

# example usage

print(countBits(2)) # Output: [0, 1, 1, 2]
print(countBits(5)) # Output: [0, 1, 1, 2, 1, 2]
print(countBits(8)) # Output: [0, 1, 1, 2, 1, 2, 2, 3]

print(countBits(0)) # Output: [0]