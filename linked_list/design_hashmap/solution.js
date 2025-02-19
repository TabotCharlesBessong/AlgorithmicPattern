class ListNode {
  constructor(key = -1, value = -1, next = null) {
    this.key = key;
    this.value = value;
    this.next = next;
  }
}

class MyHashMap {
  constructor() {
    this.size = 1000;
    this.buckets = new Array(this.size).fill(null);
  }

  hash(key) {
    return key % this.size;
  }

  put(key, value) {
    let index = this.hash(key);
    if (!this.buckets[index]) {
      this.buckets[index] = new ListNode(key, value);
      return;
    }
    let curr = this.buckets[index];
    while (curr) {
      if (curr.key === key) {
        curr.value = value;
        return;
      }
      if (!curr.next) break;
      curr = curr.next;
    }
    curr.next = new ListNode(key, value);
  }

  get(key) {
    let index = this.hash(key);
    let curr = this.buckets[index];
    while (curr) {
      if (curr.key === key) return curr.value;
      curr = curr.next;
    }
    return -1;
  }

  remove(key) {
    let index = this.hash(key);
    let curr = this.buckets[index];
    if (!curr) return;
    if (curr.key === key) {
      this.buckets[index] = curr.next;
      return;
    }
    let prev = curr;
    while (curr && curr.key !== key) {
      prev = curr;
      curr = curr.next;
    }
    if (curr) prev.next = curr.next;
  }
}
