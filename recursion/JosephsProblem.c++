//https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY
#include<bits/stdc++.h>
using namespace std;

void solve(int sword,int k,vector<int>& v){
    if(v.size()==1){
        cout<<v[0];
        return;
    }
    sword = ((sword+k)%v.size());
    v.erase(v.begin()+sword);
    solve(sword,k,v);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=1;i<=n;i++){
       v.push_back(i);
    }
    int sword =0;
    solve(sword,k-1,v);
    return 0;
}