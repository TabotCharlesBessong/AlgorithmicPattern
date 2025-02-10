class MyHashSet {
  private static final int SIZE = 10007;
  private Node[] buckets;

  static class Node {
    int key;
    Node next;

    Node(int key) {
      this.key = key;
    }
  }

  public MyHashSet() {
    buckets = new Node[SIZE];
  }

  private int _hash(int key) {
    return key % SIZE;
  }

  public void add(int key) {
    int index = _hash(key);
    if (buckets[index] == null) {
      buckets[index] = new Node(key);
      return;
    }
    Node curr = buckets[index];
    while (curr != null) {
      if (curr.key == key)
        return;
      if (curr.next == null)
        break;
      curr = curr.next;
    }
    curr.next = new Node(key);
  }

  public void remove(int key) {
    int index = _hash(key);
    Node curr = buckets[index];
    if (curr == null)
      return;
    if (curr.key == key) {
      buckets[index] = curr.next;
      return;
    }
    Node prev = null;
    while (curr != null) {
      if (curr.key == key) {
        prev.next = curr.next;
        return;
      }
      prev = curr;
      curr = curr.next;
    }
  }

  public boolean contains(int key) {
    int index = _hash(key);
    Node curr = buckets[index];
    while (curr != null) {
      if (curr.key == key)
        return true;
      curr = curr.next;
    }
    return false;
  }

  public static void main(String[] args) {
    MyHashSet hashSet = new MyHashSet();
    hashSet.add(1);
    hashSet.add(2);
    System.out.println(hashSet.contains(1)); // true
    System.out.println(hashSet.contains(3)); // false
    hashSet.add(2);
    hashSet.remove(2);
    System.out.println(hashSet.contains(2)); // false
  }
}
