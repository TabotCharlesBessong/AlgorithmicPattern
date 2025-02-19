class ListNode {
  int key, value;
  ListNode next;

  public ListNode(int key, int value) {
    this.key = key;
    this.value = value;
    this.next = null;
  }
}

class MyHashMap {
  private static final int SIZE = 1000;
  private ListNode[] buckets;

  public MyHashMap() {
    buckets = new ListNode[SIZE];
  }

  private int hash(int key) {
    return key % SIZE;
  }

  public void put(int key, int value) {
    int index = hash(key);
    if (buckets[index] == null) {
      buckets[index] = new ListNode(key, value);
      return;
    }
    ListNode curr = buckets[index];
    while (true) {
      if (curr.key == key) {
        curr.value = value; // Update value
        return;
      }
      if (curr.next == null)
        break;
      curr = curr.next;
    }
    curr.next = new ListNode(key, value);
  }

  public int get(int key) {
    int index = hash(key);
    ListNode curr = buckets[index];
    while (curr != null) {
      if (curr.key == key)
        return curr.value;
      curr = curr.next;
    }
    return -1;
  }

  public void remove(int key) {
    int index = hash(key);
    ListNode curr = buckets[index];
    if (curr == null)
      return;

    if (curr.key == key) {
      buckets[index] = curr.next;
      return;
    }

    ListNode prev = curr;
    while (curr != null && curr.key != key) {
      prev = curr;
      curr = curr.next;
    }
    if (curr != null) {
      prev.next = curr.next;
    }
  }

  public static void main(String[] args) {
    MyHashMap hashMap = new MyHashMap();
    hashMap.put(1, 10);
    hashMap.put(2, 20);
    System.out.println(hashMap.get(1)); // Output: 10
    System.out.println(hashMap.get(3)); // Output: -1
    hashMap.put(2, 25);
    System.out.println(hashMap.get(2)); // Output: 25
    hashMap.remove(2);
    System.out.println(hashMap.get(2)); // Output: -1
  }
}
