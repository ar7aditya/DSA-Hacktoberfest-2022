//QUESTION: https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        
        int n= nums.size(),i,j;
        
        for(i=n-2;i>=0;i--) //finding the break point
        {
            if(nums[i]<nums[i+1])
                break;
        }
        
        if(i<0)  //no break point was found
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        else
        {
            for(j=n-1;j>=0;j--) //number to find next permutation by swapping
            {
                if(nums[j]>nums[i])
                    break;
            }
        }
        
        swap(nums[j],nums[i]);
        reverse(nums.begin()+i+1,nums.end());
    }

int main()
{
    int n;
    cin>> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    nextPermutation(nums);

    for(int i=0;i<n;i++)
    {
        cout<<nums[i];
    }
}