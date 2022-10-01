#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
	Primes in range 0 to n:

	For a given number n,
	Display all the prime number in the range 0 to n(inclusively)

	For this problem we can use Sieve of Eratosthenes which has:
	Time Complexity: O(N*log(log(N))) ~ O(N)
	Space Complexity: O(N)
*/

vector<int> getAllPrimesTillN(int n) {
	// Creating a array to store if a num is prime of not, initially all are true
	vector<bool> isPrime(n + 1, true);

	// Base case
	isPrime[0] = false;
	isPrime[1] = false;

	// Start from 2 till the root of n
	for (int i = 2; i * i <= n; ++i)
	{
		// If i is prime then mark all its multiple as not prime
		for (int j = 2 * i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	// A vector to store all the primes
	vector<int> primes;

	for (int i = 0; i < isPrime.size(); ++i)
	{
		// If isPrime is true, then push i in primes
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}

	// Return the result
	return primes;
}

int main() {
	int n = 100;
	vector<int> primes = getAllPrimesTillN(n);

	// Displaying all the primes
	cout << "Primes: ";
	for (int i = 0; i < primes.size(); ++i)
	{
		cout << primes[i] << " ";
	}
	cout << endl;

	return 0;
};