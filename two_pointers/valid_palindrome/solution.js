
const isPalindrome = (s) => {
  let left = 0
  let right = s.length - 1

  while (left < right) {
    const leftChar = s[left].toLowerCase()
    const rightChar = s[right].toLowerCase()

    if(!/[a-zA-Z0-9]/.test(leftChar)) {
      left++
    } else if(!/[a-zA-Z0-9]/.test(rightChar)) {
      right--
    } else {
      if(leftChar !== rightChar) {
        return false
      }
      left++
      right--

    }
  }
  return true
}

// ✅ Example
console.log(isPalindrome("A man, a plan, a canal: Panama")); // true
console.log(isPalindrome("race a car"));                     // false