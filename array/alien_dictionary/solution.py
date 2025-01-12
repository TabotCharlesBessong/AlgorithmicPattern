def isAlienSorted(words: list[str], order: str) -> bool:
    char_order = {char: index for index, char in enumerate(order)}

    def in_correct_order(word1, word2):
        for c1, c2 in zip(word1, word2):
            if c1 != c2:
                return char_order[c1] < char_order[c2]
        return len(word1) <= len(word2)

    for i in range(len(words) - 1):
        if not in_correct_order(words[i], words[i + 1]):
            return False

    return True


print(isAlienSorted(words=["hello", "leetcode"], order="hlabcdefgijkmnopqrstuvwxyz"))
