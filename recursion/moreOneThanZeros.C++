//Q. print the binary number if it has more one's than zeros in it's all prefixes

#include <bits/stdc++.h>

using namespace std;

int solve(string in, int one, int zero)
{
    if (zero == 0 || one == 0)
    {
        return 1;
    }

    if (in[in.size() - 1] == '0')
    {
        zero--;
    }
    else
    {
        one--;
    }
    in.erase(in.end() - 1 + 0);
    if (zero > one)
    {
        return 0;
    }
    return solve(in, one, zero);
}

int main()
{
    int one = 0, zero = 0;
    string in = "1001";
    if (in[0] != '1')
    {
        return 0;
    }

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == '1')
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    if (zero > one)
    {
        return 0;
    }
    int n = solve(in, one, zero);
    if (n == 1)
    {
        cout << in;
    }

    return 0;
}