def isHappy(n:int) -> bool:
  visit = set()
  
  def get_next_number(n):
    total = 0
    while n > 0:
      digit = n % 10
      total += digit ** 2
      n //= 10
    return total
  
  while n not in visit:
    visit.add(n)
    n = get_next_number(n)
    if n == 1:
      return True
    
  return False



print(isHappy(28))