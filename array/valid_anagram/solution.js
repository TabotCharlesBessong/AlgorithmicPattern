
const isAnagram = (s,t) => {
  if(s.length !== t.length){
    console.log("one")
    return false
  }

  let charCount = [26]

  for (let i = 0; i < s.length; i++){
    charCount[s.charAt(i) - 'a']++
    charCount[t.charAt(i) - 'a']--
  }

  for (count of charCount){
    if (count !== 0){
      console.log("two");
      return false
    }
  }
  console.log("three");
  return true
}

console.log(isAnagram("hello","lohel"))