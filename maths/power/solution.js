
const power = (x,n) => {
  if (n === 0) return 1
  let half = power(x,Math.floor(n/2))
  return n % 2 === 0 ? half * half : half * half * x
}

const myPow = (x,n) => {
  if(n<0){
    x = 1 / x
    n = -n
  }
  return power(x,n)
}

console.log(myPow(2,10))