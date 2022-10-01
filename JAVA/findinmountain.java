import java.util.*;
public class findinmountain {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no to be searched");
        int t=sc.nextInt();
        int arr[]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,45,34,23,12,10,2,1};
        search(arr, t);
        sc.close();
        
    }
    static void search(int arr[],int t){
        int peak=mountain(arr);
        System.out.println("Peak is="+peak);
        int a=bsc(arr, t, 0, peak);
        if(a!=-1){
            System.out.println(a);
        }
        else
        System.out.println(bsc(arr, t, peak+1, arr.length-1));
    }
    static int bsc(int arr[], int t, int start, int end){
        boolean isAsc=(arr[start]<arr[end]);
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==t){
                return mid;
            }
            if(isAsc){
                if(arr[mid]<t){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                if(arr[mid]>t){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
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
