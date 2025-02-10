class MyHashSet {
  constructor() {
    this.size = 10007;
    this.buckets = new Array(this.size).fill(null).map(() => []);
  }

  _hash(key) {
    return key % this.size;
  }

  add(key) {
    const index = this._hash(key);
    if (!this.buckets[index].includes(key)) {
      this.buckets[index].push(key);
    }
  }

  remove(key) {
    const index = this._hash(key);
    this.buckets[index] = this.buckets[index].filter((num) => num !== key);
  }

  contains(key) {
    const index = this._hash(key);
    return this.buckets[index].includes(key);
  }
}

// Testing
const hashSet = new MyHashSet();
hashSet.add(1);
hashSet.add(2);
console.log(hashSet.contains(1)); // true
console.log(hashSet.contains(3)); // false
hashSet.add(2);
hashSet.remove(2);
console.log(hashSet.contains(2)); // false
