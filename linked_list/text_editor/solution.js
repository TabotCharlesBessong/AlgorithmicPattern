class TextEditor {
  constructor(text) {
    this.leftStack = []
    this.rightStack = []
  }

  addText(text){
    for (let char of text){
      this.leftStack.push(char)
    }
  }

  deleteText(k){
    let count = 0
    // delete up to k characters to the left
    while (k > 0 && this.leftStack.length > 0){
      this.leftStack.pop()
      k--
      count++
    }
    return count
  }

  cursorLeft(k){
    while (k > 0 && this.leftStack.length > 0){
      this.rightStack.push(this.leftStack.pop())
      k--
    }
    return this._getLast10()
  }

  cursorRight(k){
    while (k > 0 && this.rightStack.length > 0){
      this.leftStack.push(this.rightStack.pop())
      k--
    }
    return this._getLast10()
  }

  _getLast10(){
    // getting tje ;ast 10 characters to the left of the cursor
    return this.leftStack.slice(-10).join("")
  }
}

// example usage

let editor = new TextEditor("");
editor.addText("Hello, World!");
console.log(editor.cursorLeft(5)); // Output: "Hello, "
editor.deleteText(5);
console.log(editor.cursorLeft(2)); // Output: "Hello "