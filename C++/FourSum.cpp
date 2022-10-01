// 4Sum Problem

/*
Given an array nums of n integers,
return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/

/*
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // Sort the given vector
    sort(nums.begin(), nums.end());
    vector<vector<int>> v;
    set<vector<int>> s;
    vector<int> v1;
    int n = nums.size();
    // Iterating array by fixing first element 'a' (say)
    for (int i = 0; i < n; i++)
    {
        // Iterating array by fixing second element 'b' (say)
        for (int j = i + 1; j < n; j++)
        {
            // Calculating the sum of other two elements 'c' and 'd' (say)
            long long actualsum = long(target) - nums[i] - nums[j];
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                // if c+d = a+b then push elements into a vector and 
                // push that vector into a set to eliminate duplicate vectors
                if (nums[l] + nums[r] == actualsum)
                {
                    v1.push_back(nums[i]);
                    v1.push_back(nums[j]);
                    v1.push_back(nums[l]);
                    v1.push_back(nums[r]);
                    s.insert(v1);
                    l++;
                    r--;
                    v1.clear();
                }
                // if c+d < a+b then we need to maximise the sum
                else if (nums[l] + nums[r] < actualsum)
                {
                    l++;
                }
                // if c+d > a+b then we need to minimise the sum
                else
                {
                    r--;
                }
            }
        }
    }

    for (auto i : s)
    {
        v.push_back(i);
    }
    return v;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> answer;
    answer = fourSum(nums, target);
    cout << "The four numbers in the given array are : " << endl;
    ;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "Vector " << i + 1 << ": ";
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}