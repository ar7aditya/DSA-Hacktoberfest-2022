// Question Link :https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559
#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &stalls, int k,int mid);
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0;
    int e=stalls[stalls.size()];
    int ans=-1;

    while(s<=e){
        int mid=s+(e-s)/2;
        if(ispossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
bool ispossible(vector<int> &stalls, int k,int mid){
    int cow=1;
    int lastpos=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=mid){
            cow++;
            if(cow==k){
                return true;
            }
            lastpos=stalls[i];
        }
    }
    return false;
}
int main(){
    vector<int>hello={0 ,3 ,4 ,7 ,10 ,9};
    cout<<aggressiveCows(hello,2)<<endl;
}