const increasing = (n) => {
  for (let i = 1, p = 1; i <= n; i++, p++) {
    for (let j = 1; j <= i; j++) {
      console.log(p,"  ");
    }
    console.log("\n");
  }
};

const size = 8;

increasing(size);
