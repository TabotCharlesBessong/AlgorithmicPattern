from collections import Counter

def leastInterval(tasks, n):
    task_counts = Counter(tasks)
    maxFreq = max(task_counts.values())
    countMaxFreq = sum(1 for v in task_counts.values() if v == maxFreq)
    
    return max((maxFreq - 1) * (n + 1) + countMaxFreq, len(tasks))

# Example Usage
print(leastInterval(["A","A","A","B","B","B"], 2)) # Output: 8
