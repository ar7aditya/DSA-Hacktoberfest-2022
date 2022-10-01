// 3Sum Problem

/*
Given an integer array nums, return all the triplets
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0
*/

/*
Test case :
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

// Solution

#include <bits/stdc++.h>
using namespace std;

// threeSum function return the three numbers of array such that they add up to 0
vector<vector<int>> threeSum(vector<int> &nums)
{
    // Sort the given nums array
    sort(nums.begin(), nums.end());
    vector<vector<int>> v;
    int sum;
    // Iterate the whole nums array
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                // Calculating the sum of three numbers
                sum = nums[l] + nums[r] + nums[i];
                // If sum = 0 then push the numbers in a vector
                if (sum == 0)
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    // Move the left pointer to next different number 
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    // Move the right pointer to next different number 
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
                // If sum < 0 that means you need to increase the sum
                else if (sum < 0)
                {
                    l++;
                }
                // If sum > 0 that means you need to decrease the sum
                else
                {
                    r--;
                }
            }
        }
    }
    return v;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> answer;
    answer = threeSum(nums);
    cout << "The three numbers in the given array are : " << endl;
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