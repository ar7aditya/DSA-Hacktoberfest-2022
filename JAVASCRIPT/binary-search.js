// Binary search

const isPresent = (list, itemToSearch) => {
  // Check is we're searching in array
  if (!Array.isArray(list)) {
    throw "`list` is not an array";
  }

  // Sort the array
  const sortedList = [...list].sort();
  let lowerAnchor = 0,
    higherAnchor = sortedList.length - 1;

  while (lowerAnchor <= higherAnchor) {
    // Get middle position using `lowerAnchor` and `higherAnchor`
    const middlePosition = Math.floor((lowerAnchor + higherAnchor) / 2);
    // If the item at middle position is equal to `itemToSearch`, return `true`
    if (sortedList[middlePosition] === itemToSearch) {
      return true;
    }
    // If the item at middle position is greater than `itemToSearch`, update `higherAnchor` else update `lowerAnchor`
    if (sortedList[middlePosition] > itemToSearch) {
      higherAnchor = middlePosition - 1;
    } else {
      lowerAnchor = middlePosition + 1;
    }
  }

  // Since the `itemToSearch` is not in `list`, return `false`
  return false;
};

const list = [9, 3, 5, 7, 1, 2, 6, 0];
let itemToSearch = 3;

console.log(isPresent(list, itemToSearch)); // true

itemToSearch = 4;

console.log(isPresent(list, itemToSearch)); // false
