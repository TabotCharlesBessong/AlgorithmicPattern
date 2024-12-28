const decreasing = (n) => {
  for (let i = 1, p = n; i <= n; i++, p--) {
    for (let j = 1; j <= i; j++) {
      console.log(p, "  ");
    }
    console.log("\n");
  }
};

const size = 8;

decreasing(size);
