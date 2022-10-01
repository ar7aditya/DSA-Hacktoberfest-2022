package random;

public class recursive_linear_search {
    boolean linear_search(int arr[],int target,int element){
        //base condition
        if(target==arr.length){
            return false;
        }
        if(arr[target]==element){
            return true;
        }
        else{
            boolean remaining = linear_search(arr, target+1, element);
            return remaining;
        }
    }
    public static void main(String[] args) {
        recursive_linear_search ob = new recursive_linear_search();
        int arr[] = {1,2,3,4,5};
        System.out.println(ob.linear_search(arr, 0, 6)); 
    }
}
