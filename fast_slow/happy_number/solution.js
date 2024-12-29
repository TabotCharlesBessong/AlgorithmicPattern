const isHappy = (n) => {
  let visit = new Set()

  const getNextNumber = (n) => {
    let output = 0

    while (n > 0) {
      let digit = n % 10
      output += Math.pow(digit, 2)
      n = Math.floor(n / 10)
    }
    return output
  }

  while (!visit.has(n)) {
    if (visit.has(n)) return false
    visit.add(n)
    n = getNextNumber(n)
    if (n === 1) return true
  }
}

console.log(isHappy(19)) // true