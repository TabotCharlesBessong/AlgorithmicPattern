class ListNode:
    def __init__(self, key):
        self.key = key
        self.next = None

class MyHashSet:
    def __init__(self):
        self.size = 10007  # Prime number to reduce collisions
        self.buckets = [None] * self.size

    def _hash(self, key: int) -> int:
        return key % self.size

    def add(self, key: int) -> None:
        index = self._hash(key)
        if self.buckets[index] is None:
            self.buckets[index] = ListNode(key)
        else:
            curr = self.buckets[index]
            while True:
                if curr.key == key:
                    return  # Key already exists
                if curr.next is None:
                    break
                curr = curr.next
            curr.next = ListNode(key)

    def remove(self, key: int) -> None:
        index = self._hash(key)
        curr = self.buckets[index]
        if not curr:
            return
        if curr.key == key:
            self.buckets[index] = curr.next
            return
        prev = None
        while curr:
            if curr.key == key:
                prev.next = curr.next
                return
            prev, curr = curr, curr.next

    def contains(self, key: int) -> bool:
        index = self._hash(key)
        curr = self.buckets[index]
        while curr:
            if curr.key == key:
                return True
            curr = curr.next
        return False

# Testing
hashSet = MyHashSet()
hashSet.add(1)
hashSet.add(2)
print(hashSet.contains(1))  # Output: True
print(hashSet.contains(3))  # Output: False
hashSet.add(2)
hashSet.remove(2)
print(hashSet.contains(2))  # Output: False
