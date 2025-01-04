def beautifulArray(n: int) -> list:
  if n == 1:
    return [1]

  odd = beautifulArray((n + 1) // 2)
  even = beautifulArray(n // 2)

  result = [2 * x - 1 for x in odd] + [2 * x for x in even]
  return result

# Example
print(beautifulArray(9))  # Output: [1, 5, 3, 2, 4]
