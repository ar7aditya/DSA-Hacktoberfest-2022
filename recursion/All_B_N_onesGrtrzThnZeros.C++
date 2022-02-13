// https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18

#include <bits/stdc++.h>

using namespace std;

void solve(string op, int one, int zero,int n)
{
    if(n==0){
        cout<<op<<endl;
        return;
    }
    string op1=op;
    op1.push_back('1');
    solve(op1,one+1,zero,n-1);
    if(one>zero){
        string op2=op;
        op2.push_back('0');
        solve(op2,one,zero+1,n-1);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int one = 0, zero = 0;
    string op = "";
    solve(op, one, zero,n);
    return 0;
}