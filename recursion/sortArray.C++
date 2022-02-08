#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v, int temp){
  if(v.size()==0 || v[v.size()-1]<=temp)
  {
     v.push_back(temp);
     return ;
  }
  int val =v[v.size()-1];
  v.pop_back();
  insert(v,temp);
  v.push_back(val);
}

void sorts(vector<int>&v)
{
   if(v.size() ==1) {     
       return ;
   }
   int temp = v[v.size()-1];
   v.pop_back();
   sorts(v);   
   insert(v,temp);
  
}

int main()
{
  vector<int> v ;//={3,6,1,9,5};

  v.push_back(3);
  v.push_back(6);
  v.push_back(9);
  v.push_back(1);
  v.push_back(5);
  sorts(v);
  for(int i : v)
  cout<<i<<" ";
  return 0;
}
