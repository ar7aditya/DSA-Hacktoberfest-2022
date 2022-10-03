// Question : https://codeforces.com/problemset/problem/339/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; // Declaring a string
    cin >> s; // Taking input of a the string.

    // Using The technique of Bubble Sort we are sorting the characters in the string.
    int counter = 1;
    while (counter < s.size() - 1)
    {
        for (int i = 0; i < s.size() - counter; i++) // Here we have used s.size()-counter because once the while loop is executed then we get the highest element at the last then again the while loop will run uptil the second last value because the last element has been sorted and so on the size of the while loop decreases.
        {
            if (s[i] > s[i + 1])
            { // We are comparing every two characters in the string and if the former one is greater than the later one then we swapping them using the swap() function.
                swap(s[i], s[i + 1]);
            }
        }
        counter++; // Increasing the value of counter so that the while loop runs until we get all the elements sorted.
    }

    for (int i = (s.size() / 2); i < s.size(); i++)
    {
        if (i != s.size() - 1)
        { // Here we are checking that if the index of the string is not equal to the last index then we are printing the character with a plus sign.
            cout << s[i] << "+";
        }

        else
        { // Here as the index matches the last index hence we are not using the plus sign and printing the character as it is.
            cout << s[i];
        }
    }

    return 0;
}