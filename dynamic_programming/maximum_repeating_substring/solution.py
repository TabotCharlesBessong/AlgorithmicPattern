def maxRepeating(sequence,word):
  k = 0
  repeated_word = word
  
  while repeated_word in sequence:
    k += 1
    repeated_word += word
    
  return k

# example useage

sequence = "bananaapplebananaapplebanana"
word = "banana"
print(maxRepeating(sequence, word))  # Output: 3

sequence = "hellohellohellohellohello"

print(maxRepeating(sequence, "hello"))  # Output: 5

print(maxRepeating("ababc", "ab"))  # Output: 2
print(maxRepeating("ababc", "ba"))  # Output: 1
print(maxRepeating("ababc", "ac"))  # Output: 0