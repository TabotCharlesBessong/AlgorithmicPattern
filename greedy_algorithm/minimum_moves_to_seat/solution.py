def minMovesToSeat(seats,students):
  seats.sort()
  students.sort()
  
  return sum(abs(seats[i] - students[i]) for i in range(len(students)))

# example usage
print(minMovesToSeat([3, 1, 5], [2, 7, 4]))  # Output: 4