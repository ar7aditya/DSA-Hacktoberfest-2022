

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());    // Sort the given array to find sum easily. It is useful in last two statements of for loop.
        int min_diff = INT_MAX;          // To store the difference of target and sum of three integers
        int ans = 0;                     // to store sum of three Integers
        for(int i =0; i < nums.size(); i++)
        {
            if((i>0) && nums[i] == nums[i-1]) continue;      // If there are copied values continue;
            int l = i+1, h = nums.size()-1;   // Take two pointers
            while(l < h)
            {
                int final_sum = nums[i]+nums[l]+nums[h];      
                if(final_sum == target){          
                    return target;
                }
                if(abs(final_sum - target) < min_diff){     //if the difference between new sum value and target is lesser than previous one
                    min_diff = abs(final_sum - target);     // Change the main difference value
                    ans = final_sum;        // Make ans = sum of three integers
                } 
                if( l < h && final_sum > target) h--;         // If sum is greater than target decrease high pointer as it is making the sum greater than target
                else if(l < h && final_sum < target) l++;    // If sum is lesser than target increase low pointer as it is making the sum lesser than target;             
            }
        }
        return ans;
    }
};