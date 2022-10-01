#include <iostream>
#include <vector>
using namespace std;

/*
	Problem Statement:
	Check if Matrix Is X-Matrix

	A square matrix is said to be an X-Matrix if both of the following conditions hold:
	    1. All the elements in the diagonals of the matrix are non-zero.
	    2. All other elements are 0.

	Given a 2D integer array grid of size n x n representing a square matrix,
	return true if grid is an X-Matrix. Otherwise, return false.
*/


/*
	Time Complexity: O(N*N)
	Space Complexity: O(1)
*/
bool checkXMatrix(vector<vector<int>>& grid) {
	// n*n matrix size
	int n = grid.size();

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; ++col)
		{
			// Check if it is diagonal or not
			if (row == col || row + col == n - 1)
			{
				// return false if diagonal contians 0
				if (grid[row][col] == 0) return false;
			}
			else
			{
				// return false if non diagonal doesnot contains 0
				if (grid[row][col] != 0) return false;
			}
		}
	}

	return true;
}

int main() {
	vector<vector<int>> grid = {{2, 0, 0, 1},
		{0, 3, 1, 0},
		{0, 5, 2, 0},
		{4, 0, 0, 2}
	};

	if (checkXMatrix(grid))
	{
		cout << "Is Valid Matrix" << endl;
	}
	else
	{
		cout << "Is Not Valid Matrix" << endl;
	}

	return 0;
};