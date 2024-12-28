const basic = (n) => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      process.stdout.write("1  ");
    }
    process.stdout.write("\n");
  }
}

const size = 8;

basic(size);