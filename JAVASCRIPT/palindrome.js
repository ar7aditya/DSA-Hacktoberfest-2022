// Checks if string is palindrome or not
const isPalindrome = (string) => {
  // convert `string` to lower case
  const lowercasedString = string.toLowerCase();

  // create a reverse string
  const reversedString = lowercasedString.split("").reverse().join("");

  // check is reversed string is same as lowercased string
  return lowercasedString === reversedString;
};

console.log(isPalindrome("eve")); // true
console.log(isPalindrome("Eve")); // true
console.log(isPalindrome("even")); // false
