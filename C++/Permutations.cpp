#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> result;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        helper(nums, 0, (int)nums.size() - 1);

        return result;
    }

    void helper(vector<int> num_arr, int l, int r)
    {
        if (l == r)
        {
            result.push_back(num_arr);
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(num_arr[l], num_arr[i]);

                helper(num_arr, l + 1, r);

                swap(num_arr[l], num_arr[i]);
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sol = s.permute(nums);
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].size(); j++)
        {
            cout << sol[i][j];
        }
        cout << endl;
    }
    return 0;
}