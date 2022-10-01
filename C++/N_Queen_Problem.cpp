// Fit the given no. of queens in given chessboard matrix such that all are safe from each other
// No. of queens (N) = No. of rows/columns of chessboard

# include<bits/stdc++.h>
using namespace std;


// x = current row, y = current column
bool is_safe(int** arr, int x, int y, int n)
{
    // check safety in current column
    for (int row=0; row<x; row++)
    {
        if (arr[row][y] == 1){
            return false;
        }
    }

    // check safety diagonally
    int  row = x, col = y;
    while (row >= 0 && col >=0)
    {
        if (arr[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }

    row = x; col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

// Function to Decide positions of N Queens
bool n_queen(int** arr, int x, int n)
{
    // Base case : All N queens placed
    if (x>=n){
        return true;
    }

    for (int col=0; col<n; col++)           // Check by placing queen in every column of current row
    {          
        if (is_safe(arr, x, col, n)){
            arr[x][col] = 1;                // If queen is safe in current box, set box as 1
            
            if (n_queen(arr, x+1, n)){      // Check if and where we can place next queen in next row
                return true;                // return true is a safe position possible
            }

            arr[x][col] = 0;                // BackTrack : if safe position not possible for next queen in next row
        }
    }

    return false;
}


int main()
{
    int n;
    cout << "Enter Dimensions of chess board (no. of rows/columns) : " << endl;
    cin >> n;
    cout << endl;

    int** arr = new int*[n];
    for (int i=0; i<n; i++)
    {
        arr[i] = new int[n];
        for (int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    if (n_queen(arr, 0, n))
    {
        cout << "Chessboard Configuration : \n" << endl;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
               cout << arr[i][j] << " ";
            }
            cout << endl;
        }    
    }

    else 
    {
        cout << "No Possible Chessboard Configuration" << endl;
    }
    return 0;
}
