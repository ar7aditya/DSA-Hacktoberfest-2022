// This problem uses cyclic sort algorithm

public class findDuplicate {
    public static void main(String[] args) {
        int[] arr= {1,3,4,2,2};
        System.out.print(findDp(arr));
    }
    public static int findDp(int[] arr){
        int i=0;
        // i will run till(including) the last index of array
        while(i<arr.length){
            // to check if the element at ith index have a duplicate at the (i+1)th index
            if(arr[i] != i+1){
                int current = arr[i]-1;
                // to check if the element reside in its correct index
                if(arr[i] != arr[current]){
                    // swap the element to its correct index
                    int temp=arr[current];
                    arr[current]=arr[i];
                    arr[i]=temp;
                }
                // DUPLICATE ELEMENT FOUND
                else{
                    return arr[i];
                }
            }
            // go to the next index
            else {
                i++;
            }
        }
        return -1;
    }
}