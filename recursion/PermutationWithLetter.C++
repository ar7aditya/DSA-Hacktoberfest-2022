#include<bits/stdc++.h>
#include<set>
using namespace std;

void solve(string ip, string op,set<string>& st){
   if(ip.length()==0){
    //    cout<<op<<endl;
       st.insert(op);
       return;
   }
   string op1=op;
   string op2=op;
   op1.push_back(tolower(ip[0]));
   op2.push_back(toupper(ip[0]));
   ip.erase(ip.begin()+0);
   solve(ip,op1,st);
   solve(ip,op2,st);
}

int main(){
   set <string> st;
    string ip="a1B2";
    string op="";
    solve(ip,op,st);
    set<string> :: iterator it ;
    for(it = st.begin();it!=st.end();++it)
     cout<<(*it)<<endl ;
    return 0;
}