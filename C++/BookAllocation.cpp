/*
Problem Statement : 
Given a number of pages in N different books and M students. The books are arranged in according to the number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.Allocation is to be done in contiguous manner, every book must be given and every student must recieve a book 
*/
#include<iostream>
#include<vector>
using namespace std;
// finding possible solution for the given iteration
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}
// binary search function
int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
// Driver code
int main(){
    int n,m;
    cout<<"Enter number of books:\n";
    cin>>n;
    cout<<"Enter number of students:\n";
    cin>>m;
    //taking vector input
    vector<int> v;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    allocateBooks(v,n,m);
    return 0;
}