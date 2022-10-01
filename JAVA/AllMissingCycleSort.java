import java.util.List;
import java.util.ArrayList;
public class AllMissingCycleSort {
    public static void main(String[] args) {
        int arr[]={0,4,3,1};
        System.out.print(sort(arr));
        // for(int i=0;i<arr.length;i++){
        //     System.out.print(arr[i]+" ");
        // }
        
    }
    static int sort(int[] arr){
        int i=0;
        while(i<arr.length){
            int correct=arr[i];
            if(correct<arr.length && i!=correct){
                swap(arr,i,correct);
            }
            else i++;
        }
        List<Integer> ans=new ArrayList<>();
        i=0;
        while(i<arr.length){
            int correct=arr[i];
            if(correct==i){
                i++;
            }
            else{
            ans.add(i);
        }}
        System.out.println(ans);
        return arr.length;
    }
    static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
