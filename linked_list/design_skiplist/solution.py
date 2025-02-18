import random

MAX_LEVEL = 16

class Node:
    def __init__(self, val, level):
        self.val = val
        self.next = [None] * (level + 1)

class Skiplist:
    def __init__(self):
        self.head = Node(-1, MAX_LEVEL)

    def randomLevel(self):
        level = 0
        while random.random() < 0.5 and level < MAX_LEVEL:
            level += 1
        return level

    def search(self, target):
        curr = self.head
        for i in range(MAX_LEVEL, -1, -1):
            while curr.next[i] and curr.next[i].val < target:
                curr = curr.next[i]
        curr = curr.next[0]
        return curr is not None and curr.val == target

    def add(self, num):
        level = self.randomLevel()
        newNode = Node(num, level)
        curr = self.head
        update = [None] * (level + 1)

        for i in range(level, -1, -1):
            while curr.next[i] and curr.next[i].val < num:
                curr = curr.next[i]
            update[i] = curr

        for i in range(level + 1):
            newNode.next[i] = update[i].next[i]
            update[i].next[i] = newNode

    def erase(self, num):
        curr = self.head
        update = [None] * (MAX_LEVEL + 1)
        found = False

        for i in range(MAX_LEVEL, -1, -1):
            while curr.next[i] and curr.next[i].val < num:
                curr = curr.next[i]
            update[i] = curr

        if curr.next[0] and curr.next[0].val == num:
            found = True
            for i in range(MAX_LEVEL + 1):
                if update[i].next[i] and update[i].next[i].val == num:
                    update[i].next[i] = update[i].next[i].next[i]

        return found


# Testing Skiplist
skiplist = Skiplist()
skiplist.add(3)
skiplist.add(6)
skiplist.add(9)
skiplist.add(12)
print(skiplist.search(9))  # True
print(skiplist.search(8))  # False
skiplist.add(8)
print(skiplist.search(8))  # True
skiplist.erase(6)
print(skiplist.search(6))  # False
