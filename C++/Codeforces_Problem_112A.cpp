// Question : https://codeforces.com/problemset/problem/112/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int counter = 0;
    string s1, s2;   // DECLARING TWO STRINGS
    cin >> s1 >> s2; // TAKING THE INPUTS OF THE STRINGS.

    for (int i = 0; i < s1.size(); i++)
    {
        // Here we are converting both the strings to lowercase because 'A' and 'a' needs to be treated same in the lexicographical order.
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }

    for (int i = 0; i < s1.size(); i++)
    {

        // LOGIC : We are traversing the whole strings and as there sizes are same we can compare each of the strings completely.
        // If the characters are same then we are increasing the value of a counter by 1.
        // If we get a character in the string s1 which holds a greater position in the dictionary than the corresponding element in the string s2 then we will get the string s2 be smaller than the string s1.
        // If we get a character in the string s2 which holds a greater position in the dictionary than the corresponding element in the string s1 then we will get the string s1 be smaller than the string s2.
        if (s1[i] == s2[i])
        {
            counter++;
            continue;
        }

        else if (s1[i] > s2[i])
        {
            cout << "1" << endl;
            break;
        }
        else
        {
            cout << "-1" << endl;
            break;
        }
    }

    if (counter == s1.size())
    {
        cout << "0" << endl; // Now if we get the value of the counter equal to the size of any of the string then we can claim that no character in the two strings differ and hence the strings are equal.
    }

    return 0;
}