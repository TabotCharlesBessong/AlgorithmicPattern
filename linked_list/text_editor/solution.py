class TextEditor:
    def __init__(self):
        self.leftStack = []   # Holds characters to the left of the cursor
        self.rightStack = []  # Holds characters to the right of the cursor

    def addText(self, text: str) -> None:
        for char in text:
            self.leftStack.append(char)

    def deleteText(self, k: int) -> int:
        count = 0
        while k > 0 and self.leftStack:
            self.leftStack.pop()
            k -= 1
            count += 1
        return count

    def cursorLeft(self, k: int) -> str:
        while k > 0 and self.leftStack:
            self.rightStack.append(self.leftStack.pop())
            k -= 1
        return self._getLast10()

    def cursorRight(self, k: int) -> str:
        while k > 0 and self.rightStack:
            self.leftStack.append(self.rightStack.pop())
            k -= 1
        return self._getLast10()

    def _getLast10(self) -> str:
        return ''.join(self.leftStack[-10:])
      
# example usage
