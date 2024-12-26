const diamond = (n) => {
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      process.stdout.write("  ");
    }
    for (let j = 0; j < i; j++) {
      process.stdout.write("* ");
    }
    for (let j = 1; j < i; j++) {
      process.stdout.write("* ");
    }
    process.stdout.write("\n");
  }
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      process.stdout.write("  ");
    }
    for (let j = i + 1; j < n; j++) {
      process.stdout.write("* ");
    }
    for (let j = i; j < n; j++) {
      process.stdout.write("* ");
    }
    process.stdout.write("\n");
  }
};

const size = 8;

diamond(size);
