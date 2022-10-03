// PROGRAM TO IMPLEMENT CYCLIC SORT
// The array must be in a continuous whole or natural number form
// The logic behind this algorithm is that 
// for whole numbers, each element will reside in the index = element's value 
// for natural numbers, each element will reside in the index = element's value - 1

import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args) {
        // We have taken an array comprising natural numbers
        int[] arr={3,5,2,1,4};
        cSort(arr);
        System.out.print(Arrays.toString(arr));
    }
    public static void cSort(int[] arr){
        int i=0;

        // i will run till the length of array i.e arr-1
        while(i<arr.length){
            // arr[i] if array value starts from 0 (whole numbers), else arr[i] - 1 (natural numbers)
            int correct = arr[i]-1;
            // to check whether the the element resides in its correct index
            if(arr[i]!=arr[correct]){
                // swap the element to its correct index
                int temp=arr[correct];
                arr[correct]=arr[i];
                arr[i]=temp;
            }
            // go to the next index
            else{
                i++;
            }
        }
    }
}
