// Counting sort is a stable Sorting Algorithm
#include<bits/stdc++.h>

using namespace std;
void countSort(int a[],int n,int key)
{
     int count[50]={0};  // assigning all elements as zero
     int i,j;
    
     for(i=0;i<n;++i)
      count[a[i]]=count[a[i]]+1;  // increasing value of index(elements of array given) of count array

     cout<<"Sorted elements after applying Counting sort:";
    
     for(i=0;i<=key;++i)
      for(j=1;j<=count[i];++j)
       cout<<i<" ";
}
 
int main()
{
    int a[50],n,i,key=0;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"\nEnter elements in array:";
       // finding the masimum elements from the array 
       // to declare it as size of count array
    for(i=0;i<n;++i)
    {
     cin>>a[i];
     if(a[i]>key)
      key=a[i];
    }
    // calling counting sort
    countSort(a,n, key);
    return 0;
}
