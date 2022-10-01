public class peakmountain {
    
        public static void main(String[] args){
            int arr[]={1,2,3,4,5,6,7,8,10,20,3040,2,1};
            System.out.println(mountain(arr));
        }
        static int mountain(int arr[]){
            int start=0;
            int end=arr.length-1;
            while(start<end){
                int mid=start+(end-start)/2;
                if(arr[mid]<arr[mid+1]){
                    start=mid+1;
                }
                else{
                    end=mid;
                }
                }
                return start;
            }
}
