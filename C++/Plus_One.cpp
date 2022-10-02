//QUESTION: https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1] +1 <=9)  //case for single digit number
        {
           digits[digits.size()-1]= digits[digits.size()-1] +1;
           return digits;
        }
        
        vector<int> ans;
        
        int q=1;
        for(int i=digits.size()-1;i>=0;i--)  //adding digits one by one
        {
            int s= digits[i]+q;
            ans.push_back(s%10);
            q=s/10;
        }
        
        if(q==1)
        {
            ans.push_back(q);  //if there is a carry
        }
        
        reverse(ans.begin(),ans.end()); 
        return ans;
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

    vector<int> digits=plusOne(nums);

    for(int i=0;i<n;i++)
    {
        cout<<digits[i];
    }
}
