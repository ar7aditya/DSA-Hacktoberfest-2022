#include<bits/stdc++.h>
using namespace std;


void solve(stack<int>&st,int k)
{
   if(k==1) {     
       st.pop();
       return ;
   }
   
   int temp = st.top();
   st.pop();
   solve(st,k-1);   
   st.push(temp);
   return ;
}

int main()
{
    stack<int> st;
  st.push(3);
  st.push(6);
  st.push(9);
  st.push(1);
  st.push(5);
  int s=st.size();
  int k =s/2+1;
  solve(st,k);
  
  for(int i=st.size()-1; i>=0;i--)
  {
      cout<<st.top()<<" ";
      st.pop();
  }  
 
  return 0;
}
