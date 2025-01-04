function getSkyline(buildings) {
  function merge(left, right) {
    let result = [];
    let h1 = 0,
      h2 = 0,
      i = 0,
      j = 0;

    while (i < left.length && j < right.length) {
      let x, maxHeight;
      if (left[i][0] < right[j][0]) {
        x = left[i][0];
        h1 = left[i][1];
        i++;
      } else if (left[i][0] > right[j][0]) {
        x = right[j][0];
        h2 = right[j][1];
        j++;
      } else {
        x = left[i][0];
        h1 = left[i][1];
        h2 = right[j][1];
        i++;
        j++;
      }
      maxHeight = Math.max(h1, h2);
      if (result.length === 0 || result[result.length - 1][1] !== maxHeight) {
        result.push([x, maxHeight]);
      }
    }
    result.push(...left.slice(i));
    result.push(...right.slice(j));
    return result;
  }

  function divideAndConquer(start, end) {
    if (start === end) {
      const [l, r, h] = buildings[start];
      return [
        [l, h],
        [r, 0],
      ];
    }

    const mid = Math.floor((start + end) / 2);
    const left = divideAndConquer(start, mid);
    const right = divideAndConquer(mid + 1, end);
    return merge(left, right);
  }

  return divideAndConquer(0, buildings.length - 1);
}

console.log(
  getSkyline([
    [2, 9, 10],
    [3, 7, 15],
    [5, 12, 12],
    [15, 20, 10],
    [19, 24, 8],
  ])
);
