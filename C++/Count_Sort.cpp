// Count sort

// Input :
// line 1 : n = number of entries
// line 2 : all n entries

# include<bits/stdc++.h>
using namespace std;

void count_sort(int arr[], int n, int ans[])
{

    //find max array element
    int arr_max = arr[0];
    for (int i=0; i<n; i++){
        arr_max = max(arr_max, arr[i]);
    }

    //store occurences of each number
    int count[arr_max+1] = {0};
    for (int i=0; i<n; i++){
        count[arr[i]] += 1;
    }

    for (int i=1; i<=arr_max; i++){
        count[i] += count[i-1];
    }

    for (int i=n-1; i>=0; i--){
        ans[--count[arr[i]]] = arr[i];
    }
    return;
}

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    int ans[n];

    //input array to sort
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    count_sort(arr, n, ans);

    //output sorted array
    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
