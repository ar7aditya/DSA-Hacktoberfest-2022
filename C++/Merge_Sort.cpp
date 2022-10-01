// Merge Sort

# include <bits/stdc++.h>
using namespace std;

void merge (int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;                       // size of first half 
    int n2 = r - mid;                           // size of second half

    // create half arrays
    int a[n1];                                  
    int b[n2];

    // enter values in half arrays
    for (int i=0; i<n1; i++){                   
        a[i] = arr[l+i];
    }
    
    for (int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }

    // i = traverse a[], j = traverse b[], k = traverse arr[]
    int i=0, j=0, k=l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j]){
            arr[k] = a[i];
            i++; k++;
        }

        else {
            arr[k] = b[j];
            j++; k++;
        }
    }

    // Case : array b[] ends but a[] remains
    while (i < n1){
        arr[k] = a[i];
        i++; k++;
    }

    // Case : array a[] ends but b[] remains
    while (j < n2){
        arr[k] = b[j];
        j++; k++;
    }
}


void merge_sort (int arr[], int l, int r)
{
    if (l<r){                                   // If split-array has more than 1 element
        int mid = (l+r)/2 ;                     // define mid 
        merge_sort(arr, l, mid);                // sort 1st half array
        merge_sort(arr, mid+1, r);              // sort 2nd half array

        merge(arr,l,mid,r);                     // merge two sorted halves
    }
    return;
}


int main()
{
    // Array Input
    int n;
    cout << "Enter No. of Entries : " << endl;
    cin >> n;
    int arr[n];

    cout << "\nEnter Numbers : " << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int l = 0, r = n-1;
    merge_sort(arr, l, r);

    // Output 
    cout << "\nSorted Output :" << endl;
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}
