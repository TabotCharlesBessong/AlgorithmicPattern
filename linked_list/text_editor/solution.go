package main

type TextEditor struct {
	leftStack  []rune
	rightStack []rune
}

func Contructor() TextEditor {
	return TextEditor{
		leftStack:  []rune{},
		rightStack: []rune{},
	}
}

func (this *TextEditor) AddText(text string) {
	for _, char := range text {
		this.leftStack = append(this.leftStack, char)
	}
}

func (this *TextEditor) DeleteText(k int) int {
	count := 0
	for k > 0 && len(this.leftStack) > 0 {
		this.leftStack = this.leftStack[:len(this.leftStack)-1]
		k--
		count++
	}
	return count
}

func (this *TextEditor) CursorLeft(k int) string {
	for k > 0 && len(this.leftStack) > 0 {
		char := this.leftStack[len(this.leftStack)-1]
		this.leftStack = this.leftStack[:len(this.leftStack)-1]
		this.rightStack = append(this.rightStack, char)
		k--
	}
	return this.getLast10()
}

func (this *TextEditor) CursorRight(k int) string {
	for k > 0 && len(this.rightStack) > 0 {
		char := this.rightStack[len(this.rightStack)-1]
		this.rightStack = this.rightStack[:len(this.rightStack)-1]
		this.leftStack = append(this.leftStack, char)
		k--
	}
	return this.getLast10()
}

func (this *TextEditor) getLast10() string {
	start := len(this.leftStack) - 10
	if start < 0 {
		start = 0
	}
	return string(this.leftStack[start:])
}

func main() {
	
}