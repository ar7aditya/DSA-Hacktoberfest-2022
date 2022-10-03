// To find the missing positive number in a natural/whole number array
// uses cyclicSort

public class missingPositive {
    public static void main(String[] args) {
        int[] arr={3,4,-1,1};
        System.out.print(firstMissingPositive(arr));
    }
    public static int firstMissingPositive(int[] arr) {
        int i=0;
        // i will run till(including) the last index of array
        while(i<arr.length){
            int current = arr[i]-1;
            // to check if the element reside in its correct index
            if( arr[i] > 0 && arr[i] < arr.length && arr[i]!=arr[current]){
                // swap the array element to its correct index
                int temp=arr[current];
                arr[current]=arr[i];
                arr[i]=temp;
            }
            else{
                i++;
            }
        }
        // Search for missing positive number
        for (int j = 0; j < arr.length; j++) {
            if(arr[j] != j+1){
                return j+1;
            }
        }
        // if none found then the last element is missing
        return arr.length + 1;
    }
}