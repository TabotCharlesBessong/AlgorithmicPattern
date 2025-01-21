const convertToTitle = (n) => {
  let result = '';
  while (n > 0) {
    n--;
    result = String.fromCharCode((n % 26) + 65) + result;
    n = Math.floor(n / 26);
  }
  return result;
}

console.log(convertToTitle(26)); // Z
 console.log(convertToTitle(27)); // AA
 console.log(convertToTitle(701)); // ZY
 console.log(convertToTitle(702)); // ZZ