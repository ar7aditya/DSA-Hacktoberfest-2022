#include<bits/stdc++.h>
#include<set>
using namespace std;


void solve(string in, string out,set<string>& st){
     if(in.length()==0)
   {
       st.insert(out);
       return;
   }
   string out1= out;
   string out2= out ;
   out1.push_back(in[0]);
   out2.push_back('_');
   out2.push_back(in[0]);
   in.erase(in.begin()+0);
  
   solve(in,out1,st);
   solve(in,out2,st);
}

int main(){
    set <string> st;
    string in="abcd";
    string out="";
    out.push_back(in[0]);
    in.erase(in.begin()+0);
    solve(in,out,st);
    
    set<string> :: iterator it ;
    for(it = st.begin();it!=st.end();++it)
     cout<<(*it)<<endl ;
    return 0;
}