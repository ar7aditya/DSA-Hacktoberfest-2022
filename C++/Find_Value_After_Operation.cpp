#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
	Problem Overview:
	Final Value of Variable After Performing Operations
	There is a programming language with only four operations and one variable X:
    ++X and X++ increments the value of the variable X by 1.
    --X and X-- decrements the value of the variable X by 1.

	Initially, the value of X is 0.
	Given an array of strings operations containing a list of operations,
	return the final value of X after performing all the operations.

	Example 1:
	Input: operations = ["--X","X++","X++"]
	Output: 1
	Explanation:
	The operations are performed as follows:
	Initially, X = 0.
	--X: X is decremented by 1, X =  0 - 1 = -1.
	X++: X is incremented by 1, X = -1 + 1 =  0.
	X++: X is incremented by 1, X =  0 + 1 =  1.
*/

/*
	The intuition for solving this problem is to see that there
	are only 4 types of input X++, ++X, X-- and --X
	and so know if it is + or - we can simply see the middle char i.e char at index 1
	if it is + then add else subtract

	For the below Function:
	Time Complexity: O(N)
	Space Complexity: O(1)
*/
int finalValueAfterOperations(vector<string>& operations) {
	int X = 0;

	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][1] == '+') X++;
		else X--;
	}

	return X;
}

int main() {
	vector<string> operations = {"++X", "++X", "X++"};

	int X = finalValueAfterOperations(operations);
	cout << "X: " << X << endl;

	return 0;
};