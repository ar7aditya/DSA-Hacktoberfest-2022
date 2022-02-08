#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&st, int temp){
  if(st.size()==0 || st.top()<=temp)
  {
     st.push(temp);
     return ;
  }
  int val =st.top();
  st.pop();
  insert(st,temp);
  st.push(val);
}

void sorts(stack<int>&st)
{
   if(st.size() ==1) {     
       return ;
   }
   int temp = st.top();
   st.pop();
   sorts(st);   
   insert(st,temp);
  
}

int main()
{
    stack<int> st;
  st.push(3);
  st.push(6);
  st.push(9);
  st.push(1);
  st.push(5);
  sorts(st);
  int s=st.size();
int arr[10];
  for(int i=st.size()-1; i>=0;i--)
  {
      arr[i]= st.top();
      st.pop();
  }  
  for(int i=0; i<s;i++)
  {
      cout<<arr[i]<<" ";
  }  
  return 0;
}
