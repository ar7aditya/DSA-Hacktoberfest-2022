#include<bits/stdc++.h>
using namespace std;
void solve(int s,int d,int h,int n){
   if(n==1){
       cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
       return ;
   }
   solve(s,h,d,n-1);
   cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
   solve(h,d,s,n-1);
  return ;
}

int main(){
     int n;
     cin>>n;
     int s=1,h=2,d=3;
    solve(s,d,h,n);
    return 0;
}