import java.util.Arrays;

class MergeSort {
    /*
    Using merge sort(in-place) which is taking TC:O(NlogN)
    */

    public static void msort(int[] nums,int s,int e){
       if(e-s==1){
           return;
       }
        int mid=s+(e-s)/2;
        /*
         * Dividing sub-arrays by mid values till sub-array length reaches 1
         */
        msort(nums,s,mid); 
        msort(nums,mid,e);
        merge(nums,s,mid,e);
    }
    // using in-place techniques to reduce unnecessary space issues, thereby reducing space complexity
    public static void merge(int[] nums,int s,int mid,int e){
        int[] mix=new int[e-s];
        int i=s,j=mid,k=0;
        // adding elements in the mix array in ascending order
        while(i<mid && j<e){
            if(nums[i]>nums[j]){
                mix[k]=nums[j];
                j++;
            }else{
                mix[k]=nums[i];
                i++;
            }
            k++;
        }
        // now adding the left out elements whether, of elements of i or j
        while(i<mid){
            mix[k]=nums[i];
            i++;
            k++;
        }
        while(j<e){
            mix[k]=nums[j];
            j++;
            k++;
        }
        for(int l=0;l<(e-s);l++){
            nums[s+l]=mix[l];
        }
    }
    // function to swap the arrays values
    public void swap(int[] arr,int s,int e){
        int temp=arr[e];
        arr[e]=arr[s];
        arr[s]=temp;
    }
    public static void main(String[] args) {
        int[] arr={10,9,8,7,6,5,4,3,2,1};
        System.out.println("Input Array: "+Arrays.toString(arr));
        msort(arr,0,arr.length);
        System.out.println("Output Array: "+Arrays.toString(arr));
    }
}