class Node {
  constructor(val, level) {
    this.val = val;
    this.next = new Array(level + 1).fill(null);
  }
}

class Skiplist {
  constructor() {
    this.MAX_LEVEL = 16;
    this.head = new Node(-1, this.MAX_LEVEL);
  }

  randomLevel() {
    let level = 0;
    while (Math.random() < 0.5 && level < this.MAX_LEVEL) {
      level++;
    }
    return level;
  }

  search(target) {
    let curr = this.head;
    for (let i = this.MAX_LEVEL; i >= 0; i--) {
      while (curr.next[i] && curr.next[i].val < target) {
        curr = curr.next[i];
      }
    }
    curr = curr.next[0];
    return curr !== null && curr.val === target;
  }

  add(num) {
    let level = this.randomLevel();
    let newNode = new Node(num, level);
    let curr = this.head;
    let update = new Array(level + 1).fill(null);

    for (let i = level; i >= 0; i--) {
      while (curr.next[i] && curr.next[i].val < num) {
        curr = curr.next[i];
      }
      update[i] = curr;
    }

    for (let i = 0; i <= level; i++) {
      newNode.next[i] = update[i].next[i];
      update[i].next[i] = newNode;
    }
  }

  erase(num) {
    let curr = this.head;
    let update = new Array(this.MAX_LEVEL + 1).fill(null);
    let found = false;

    for (let i = this.MAX_LEVEL; i >= 0; i--) {
      while (curr.next[i] && curr.next[i].val < num) {
        curr = curr.next[i];
      }
      update[i] = curr;
    }

    if (curr.next[0] && curr.next[0].val === num) {
      found = true;
      for (let i = 0; i <= this.MAX_LEVEL; i++) {
        if (update[i].next[i] && update[i].next[i].val === num) {
          update[i].next[i] = update[i].next[i].next[i];
        }
      }
    }
    return found;
  }
}

// Example Usage
let skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
console.log(skiplist.search(0)); // false
skiplist.add(4);
console.log(skiplist.search(1)); // true
skiplist.add(5);
console.log(skiplist.search(3)); // true
console.log(skiplist.search(6)); // false
