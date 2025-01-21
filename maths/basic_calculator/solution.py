def calculate(s:str) -> int:
  stack = []
  currentNumber = 0
  operation = '+'
  s = s.replace(" ","")
  
  for i, char in enumerate(s):
    if char.isdigit():
      currentNumber = currentNumber * 10 + int(char)
      
    if char in ['+', '-', '*', '/'] or i == len(s) - 1:
      if operation == '+':
        stack.append(currentNumber)
      elif operation == '-':
        stack.append(-currentNumber)
      elif operation == '*':
        stack.append(stack.pop() * currentNumber)
      elif operation == '/':
        if stack[-1] == 0:
          raise ZeroDivisionError('Division by zero')
        stack.append((stack.pop() / currentNumber))
      
      operation = char
      currentNumber = 0
      
  return sum(stack)

# Example usage

print(calculate("3 + 2 * 2"))  # Output: 7
print(calculate("14-3/2"))  # Output: 13
print(calculate(" 3+5 / 2 "))  # Output: 5
