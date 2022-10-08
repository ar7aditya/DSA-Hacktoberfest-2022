#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// using Loop
void Palindrome(string s)
{

    string reverseString = "";

    for (int i = s.length() - 1; i >= 0; i--)
    {
        reverseString = reverseString + s[i];
    }

    if (s == reverseString)
    {
        cout << "true" << endl;
    }

    else
    {
        cout << "False" << endl;
    }
}

int main()
{

    string s;
    cout << "pls enter a string" << endl;
    cin >> s;

    Palindrome(s);

    return 0;
}
