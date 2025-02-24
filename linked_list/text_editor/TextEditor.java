import java.util.Stack;

class TextEditor {
  Stack<Character> leftStack;
  Stack<Character> rightStack;

  public TextEditor() {
    leftStack = new Stack<>();
    rightStack = new Stack<>();
  }

  public void addText(String text) {
    for (char ch : text.toCharArray()) {
      leftStack.push(ch);
    }
  }

  public int deleteText(int k) {
    int count = 0;
    while (k > 0 && !leftStack.isEmpty()) {
      leftStack.pop();
      k--;
      count++;
    }
    return count;
  }

  public String cursorLeft(int k) {
    while (k > 0 && !leftStack.isEmpty()) {
      rightStack.push(leftStack.pop());
      k--;
    }
    return getLast10();
  }

  public String cursorRight(int k) {
    while (k > 0 && !rightStack.isEmpty()) {
      leftStack.push(rightStack.pop());
      k--;
    }
    return getLast10();
  }

  private String getLast10() {
    StringBuilder sb = new StringBuilder();
    for (int i = Math.max(0, leftStack.size() - 10); i < leftStack.size(); i++) {
      sb.append(leftStack.get(i));
    }
    return sb.toString();
  }
}