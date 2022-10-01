package random;
import java.util.*;
public class pancake_sorting {
    public static void main(String[] args) {
        int arr[] = {7,8,9,1};
        pancake_sorting ob = new pancake_sorting();
        ob.pancakeSort(arr);
        System.out.println(Arrays.toString(arr));
        
    }
    public List<Integer> pancakeSort(int[] arr) {
        List<Integer> l = new ArrayList<>();
        for(int i =arr.length-1;i>=0;i--){
            int maxIndex = i;
            for(int j=i-1;j>=0;j--){
                if(arr[j]>arr[maxIndex]){
                    maxIndex = j;
                }
            }
            if(maxIndex!=i)//basically if the element is not at its correct position
            {
                reverse(arr,0,maxIndex);
                l.add(maxIndex+1);

                reverse(arr,0,i);
                l.add(i+1);
            }
        }
        return l;
    }
    private void reverse(int[] arr, int low, int high) {
        while(low<=high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
}
