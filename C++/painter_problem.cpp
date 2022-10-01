//Question Link : https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557
#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> &boards, int k,int m){
    int paint=1;
    int wc=0;
    for(int i=0;i<boards.size();i++){
        if(wc+boards[i]<=m){
            wc+=boards[i];
        }
        else{
            paint++;
            if(paint>k || boards[i]>m){
                return false;
            }
                wc=boards[i];
        }
           if(paint > k) {
            return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    for(auto i:boards){
        sum+=i;
    }
    int e=sum;
    int ans=-1;
        int mid=s+(e-s)/2;
    while(s<=e){
        if(ispossible(boards,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int> walls={10 ,20 ,30 ,40};
    cout<<findLargestMinDistance(walls,2)<<endl;
}