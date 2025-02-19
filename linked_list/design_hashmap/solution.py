class ListNode:
    def __init__(self, key=-1, value=-1, next=None):
        self.key = key
        self.value = value
        self.next = next

class MyHashMap:
    def __init__(self):
        self.size = 1000  # Number of buckets
        self.buckets = [None] * self.size  # Array of linked lists

    def hash(self, key: int) -> int:
        return key % self.size  # Hash function

    def put(self, key: int, value: int) -> None:
        index = self.hash(key)
        if self.buckets[index] is None:
            self.buckets[index] = ListNode(key, value)  # Create a new node if bucket is empty
        else:
            curr = self.buckets[index]
            while True:
                if curr.key == key:
                    curr.value = value  # Update value if key exists
                    return
                if curr.next is None: break
                curr = curr.next
            curr.next = ListNode(key, value)  # Insert at end of the list

    def get(self, key: int) -> int:
        index = self.hash(key)
        curr = self.buckets[index]
        while curr:
            if curr.key == key:
                return curr.value  # Return value if key is found
            curr = curr.next
        return -1  # Key not found

    def remove(self, key: int) -> None:
        index = self.hash(key)
        curr = self.buckets[index]
        if not curr: return  # If bucket is empty, return

        if curr.key == key:
            self.buckets[index] = curr.next  # Remove head node
        else:
            prev = curr
            while curr and curr.key != key:
                prev = curr
                curr = curr.next
            if curr:
                prev.next = curr.next  # Remove the node from the list

# Example Usage:
hash_map = MyHashMap()
hash_map.put(1, 10)
hash_map.put(2, 20)
print(hash_map.get(1))  # Output: 10
print(hash_map.get(3))  # Output: -1 (not found)
hash_map.put(2, 25)  # Update value
print(hash_map.get(2))  # Output: 25
hash_map.remove(2)
print(hash_map.get(2))  # Output: -1 (removed)
