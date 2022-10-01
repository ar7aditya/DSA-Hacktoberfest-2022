#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortColors(vector<int> &nums)
    {
        int l = 0, m = 0, h = nums.size() - 1;
        while (m <= h)
        {
            if (nums[m] == 0)
            {
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
            {
                m++;
            }
            else
            {
                swap(nums[m], nums[h]);
                h--;
            }
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 0, 1, 2, 2, 0, 0, 1, 0, 0, 2};
    vector<int> sol = s.sortColors(nums);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << endl;
    }
    return 0;
}