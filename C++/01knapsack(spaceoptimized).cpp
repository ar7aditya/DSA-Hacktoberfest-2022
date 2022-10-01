/*
    AUTHOR - Prachhi Sabita Mishra
*/
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    // making and initializing dp array
    vector<int> dp(W + 1, 0);
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the max value of knapsack
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
