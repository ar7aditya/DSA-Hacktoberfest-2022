// Quick Sort

# include <bits/stdc++.h>
using namespace std;


// Function to swap elements of array
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}


// Function to partition around pivot, i.e, separate smaller and greater numbers into two arrays
// and return correct index of pivot 
int partition(int arr[], int l, int r)
{
    // select pivot element, here, last element of array
    int pivot = arr[r];
    // i = points to last number in array less than pivot 
    int i = l-1;

    // traverse array from l'th to r-1'th element
    for (int j=l; j<r; j++)
    {
        // if jth element less than pivot then swap it with ith element and increment i
        if (arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }

    // Swap pivot with (i+1)th element, i.e, its correct position
    swap(arr, i+1, r);
    return i+1;
}


// Function to sort array : l = leftmost index, r =  rightmost index
void quick_sort(int arr[], int l, int r)
{
    if (l<r)
    {
        // pi = pivot index, assume last element as pivot
        int pi = partition(arr, l, r);

        // Quick Sort in elements smaller than pivot
        quick_sort(arr, l, pi-1);
        // Quick Sort in elements greater than pivot
        quick_sort(arr, pi+1, r);
    }
    return;
}


int main()
{
    // Input Array
    int n;
    cout << "Enter no. of elements to sort :" << endl;
    cin >> n;

    int arr[n];
    cout << "\nEnter numbers to be sorted : " << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    // Perform Quick Sort 
    quick_sort(arr, 0, n-1);

    // Output Sorted array
    cout << "\nSorted Numbers : " << endl;
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
