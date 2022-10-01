// Sieve of Eratosthenes

const getPrimes = (highestNumber) => {
  // Create a intermediate array which would store is the index number is prime or not as we iterate over it.
  const hashArray = Array(highestNumber).fill(false);

  // List of all primes
  let primes = [];

  for (let number = 2; number <= highestNumber; number++) {
    // `number` is not prime, just continue iteration
    if (hashArray[number]) {
      continue;
    }

    // `number` is prime, so add it in list.
    primes = [...primes, number];
    for (
      let currentNumber = number;
      currentNumber <= highestNumber;
      currentNumber += number
    ) {
      // Mark all the multiples of `number` as non-prime
      hashArray[currentNumber] = true;
    }
  }

  return primes;
};

const highestNumber = 1000;
const primes = getPrimes(highestNumber);

console.log(`Primes from 0 to ${highestNumber} :- `, primes);
