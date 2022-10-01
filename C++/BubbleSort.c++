#include <bits/stdc++.h>
using namespace std;

// Function for bubble sort algorithm
void bubbleSort(vector<int> &arr ){
    if (arr.size() == 1 || arr.size() == 0){
        return;
    }

    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr.size()-i-1; j++){
            // condition for swapping (if any element is greater than the next element, then swap them)
            if (arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
            }
        }
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

    bubbleSort(arr);

    // printing sorted array/vector
    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}