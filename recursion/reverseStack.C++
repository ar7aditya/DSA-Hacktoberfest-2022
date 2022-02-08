#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&st, int temp){
if(st.size()==0){
    st.push(temp);
    return;
}
int top =st.top();
st.pop();
insert(st,temp);
st.push(top);
}

void reverse(stack<int>&st)
{
   if(st.size()==0){
       return ;
   }
   
   int temp = st.top();
   st.pop();
   reverse(st);   
   insert(st,temp);//induction
   return ;
}

int main()
{
    stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  reverse(st);
  
  for(int i=0; i<5;++i)
  {
      cout<<st.top()<<" ";
      st.pop();
  }  
 
  return 0;
}
