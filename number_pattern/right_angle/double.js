const double = (n) => {
  for (let i = 1, p = 0; i <= n; i++, p +=2) {
    for (let j = 1; j <= i; j++) {
      console.log(p, "  ");
    }
    console.log("\n");
  }
};

const size = 8;

double(size);
