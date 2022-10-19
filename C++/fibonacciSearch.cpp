#include <bits/stdc++.h>
using namespace std;

int fibonacciSearch(vector<int> arr, int n, int key)
{

    int b = 0, a = 1;

    int f = b + a; // fibonacci term

    while (f < n)
    {
        b = a;
        a = f;
        f = b + a;
    }

    int done = -1; // index upto which checked

    while (f > 1)
    {
        int i = min(done + b, n - 1);

        if (arr[i] < key)
        { // to search in upper bound
            f = a;
            a = b;
            b = f - a;
            done = i;
        }

        else if (arr[i] > key)
        { // tosearch in lower bound
            f = b;
            a = a - b;
            b = f - a;
        }
        else // if element matched
            return i;
    }
    if (a && arr[done + 1] == key) // edge case if element is on last index (n-1)
        return ++done;
    return -1; // if element is not found
}

int main()
{

    int n;
    cout << "Number of elements :   ?\t";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter element\t";
        cin >> x;
        arr.push_back(x);
    }
    cout << endl;
    sort(arr.begin(), arr.end());
    for (int p : arr)
        cout << p << "\t";
    cout << endl;

    cout << "Enter key\t";
    int k;
    cin >> k;
    if (fibonacciSearch(arr, arr.size(), k) == -1)
        cout << k << " is not found " << endl;
    else
        cout << k << " found at index " << fibonacciSearch(arr, arr.size(), k) << endl;
    return 0;
}