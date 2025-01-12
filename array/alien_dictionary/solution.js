const inCorrectOrder = (word1, word2, charOrder) => {
  let minLength = Math.min(word1, word2);
  for (let i = 0; i < minLength; i++) {
    if (word1[i] !== word2[i]) {
      return charOrder.get(word1[i]) < charOrder.get(word2[i]);
    }
  }
  return word1.length <= word2.length;
};

const isAlienSorted = (words, order) => {
  const charOrder = new Map();
  for (let i = 0; i < order.length; i++) {
    charOrder.set(order[i], i);
  }

  for (let i = 0; i < words.length - 1; i++) {
    if (!inCorrectOrder(words[i], words[i + 1], charOrder)) return false;
  }
  return true;
};

console.log(
  isAlienSorted(
    (words = ["hello", "leetcode"]),
    (order = "hlabcdefgijkmnopqrstuvwxyz")
  )
);