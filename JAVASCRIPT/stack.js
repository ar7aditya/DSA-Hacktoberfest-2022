// Create a class called `Stack`
class Stack {
  items = [];

  push(item) {
    this.items = [...this.items, item];
  }

  pop() {
    const topItem = this.items.pop();
    return topItem;
  }

  peek() {
    return this.items[0];
  }

  toString() {
    console.log(this.items);
  }

  getSize() {
    return this.items.length;
  }

  isEmpty() {
    const size = this.getSize();
    return size === 0;
  }
}

// Function to reverse the string
const reverse = (string) => {
  // Create a empty stack
  const stack = new Stack();
  let reversedString = "";

  // Push all the characters in string in stack
  [...string].forEach((character) => stack.push(character));

  // Keep on popping all the characters from stack until it's empty
  while (!stack.isEmpty()) {
    const poppedCharacter = stack.pop();
    // Append popped character to reversed string
    reversedString = `${reversedString}${poppedCharacter}`;
  }
  return reversedString;
};

console.log(reverse("Hello")); // olleH
