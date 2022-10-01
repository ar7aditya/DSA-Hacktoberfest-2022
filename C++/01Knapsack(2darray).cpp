/*
    AUTHOR - Prachhi Sabita Mishra
*/
#include<bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    // Build table dp[][] in bottom up manner
    // where dp[i][j] will denote maximum value of ‘j-weight’ considering all values from ‘1 to ith’
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    int W, n; // weight max and the size of array
    cin>>W>>n;
    vector<int> val(n); // price array
    for (int i = 0; i < n; i++)
        cin >> val[i];

    vector<int> wt(n); // weight array
    for (int i = 0; i < n; i++)
        cin >> wt[i];

	cout << knapSack(W, wt, val, n);
	return 0;
}
