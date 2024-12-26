const decreasing = (n) => {
  for (let i = n; i > 0; i--) {
    for (let j = 0; j < i; j++) {
      process.stdout.write("*  ");
    }
    process.stdout.write("\n");
  }
};

const size = 8;

decreasing(size);
