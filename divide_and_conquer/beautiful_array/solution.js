const beautifulArray = (n) => {
  if (n === 1) return [1];

  const odd = beautifulArray(Math.ceil(n / 2));
  const even = beautifulArray(Math.floor(n / 2));

  const result = [];
  for (let x of odd) result.push(2 * x - 1);
  for (let x of even) result.push(2 * x);

  return result;
};

console.log(beautifulArray(10)); // [1,5,3,2,6,4]
