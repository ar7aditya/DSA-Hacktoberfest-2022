#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int indexSequentialSearch(vector<int> a, int n, int k)
{
    int groupNo = 3;
    // number of elements in a grp
    int idx[groupNo];
    int data[groupNo];

    int j = 0, ind = 0, start, end;
    int i, set = 0;

    for (i = 0; i < n; i += 3)
    {
        // Storvalue
        data[ind] = a[i];

        // Stort index
        idx[ind] = i;
        ind++;
    }
    if (k < data[0])
        // invalid case
        return -1;

    else
    {
        for (i = 1; i <= ind; i++)
            if (k <= data[i])
            {
                // updaing the condition variables
                start = idx[i - 1];
                end = idx[i];
                set = 1;
                break;
            }
    }
    if (set == 0)
    {
        start = idx[groupNo - 1];
        end = groupNo;
    }
    for (i = start; i <= end; i++)
    {
        if (k == a[i])
        {
            j = 1;
            break;
        }
    }
    if (j == 1)
        return i;
    else
        return -1;
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
    // sort(arr.begin(), arr.end());
    for (int p : arr)
        cout << p << "\t";
    cout << endl;

    cout << "Enter key\t";
    int k;
    cin >> k;
    if (indexSequentialSearch(arr, arr.size(), k) == -1)
        cout << k << " is not found " << endl;
    else
        cout << k << " found at index " << indexSequentialSearch(arr, arr.size(), k) << endl;
    return 0;
}