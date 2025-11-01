
const isAnagram = (s,t) => {
  if(s.length !== t.length){
    // console.log("one")
    return false
  }

  const charCount = new Array(26).fill(0);

  for (let i = 0; i < s.length; i++){
    charCount[s.charCodeAt(i) - 'a'.charCodeAt(0)]++
    charCount[t.charCodeAt(i) - 'a'.charCodeAt(0)]--
  }

  for (let count of charCount){
    if (count !== 0){
      // console.log("two");
      return false
    }
  }
  // console.log("three");
  return true
}

console.log(isAnagram("hello","lohel"))