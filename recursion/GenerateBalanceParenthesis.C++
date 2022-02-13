#include <bits/stdc++.h>
#include <set>
using namespace std;

void solve(int n, string op, set<string> &ss)
{
    if (n == 0)
    {
        ss.insert(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back('(');
    op2.push_back(')');
    n = n - 1;
    solve(n, op1, ss);
    solve(n, op2, ss);
}

int main()
{
    set<string> ss;
    int n ;
    cin>>n;
    string op = "(";
    solve(n * 2 - 1, op, ss);

    set<string>::iterator it;
    for (it = ss.begin(); it != ss.end(); ++it)
    {
        stack<char> st;
        int flag=0;
        for (char symbol : *it)
        {
            if (symbol == '(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty()){
                    flag=1;
                    break;
                }
                if (!st.empty()){
                 st.pop();
                }  
                
            }
        }
        if (st.empty()&& flag ==0)
        {
            cout << *it << endl;
        }
    }

    return 0;
}