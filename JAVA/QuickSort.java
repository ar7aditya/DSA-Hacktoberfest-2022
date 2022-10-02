import java.util.Arrays;

class QuickSort {
    /*
    Using quick sort which is taking pivot as median element



    By choosing pivot as corner element results in TLE because TC grows to O(N^2)
    instead of O(NlogN)
    */
    public static void sort(int[] nums,int low,int high){
        if(low>=high){
            return;
        }
        int s=low;
        int e=high;
        int mid=s+(e-s)/2;
        int pivot=nums[mid]; // selecting the pivot elements as mid value for more optmised solution
        while(s<=e){
            while(nums[s]<pivot){
                s++;
            }
            while(nums[e]>pivot){
                e--;
            }
            if(s<=e){
                swap(nums,s,e);
                s++;
                e--;
            }
        }
        sort(nums,low,e);
        sort(nums,s,high);
    }
    // function to swap the arrays values
    public static void swap(int[] arr,int s,int e){
        int temp=arr[e];
        arr[e]=arr[s];
        arr[s]=temp;
    }
    public static void main(String[] args) {
        int[] arr={10,9,8,7,6,5,4,3,2,1};
        System.out.println("Input Array: "+Arrays.toString(arr));
        sort(arr,0,arr.length-1);
        System.out.println("Output Array: "+Arrays.toString(arr));
    }
}