#include <bits/stdc++.h>
using namespace std;

// Function for selection sort algorithm
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_index = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min_index])
            min_index = j;
 
        // Swap the found minimum element with the first element
        if(min_index != i)
            swap(arr[min_index], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    selectionSort(arr);

    // printing sorted array/vector
    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}