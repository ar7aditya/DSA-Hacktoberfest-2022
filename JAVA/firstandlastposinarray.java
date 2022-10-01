import java.util.*;
public class firstandlastposinarray {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int[] arr={1,5,5,7,7,7,7,8,10};
        System.out.println("Enter the number");
        int t=sc.nextInt();
        search(arr,t);
        sc.close();
    }
    static void search(int[] arr, int t){
        //to search for first occurence and hen last occ
        int[] ans={-1,-1};
        ans[0]=bsc(arr,t,true);
        ans[1]=bsc(arr,t,false);
        System.out.println(ans[0]);
        System.out.println(ans[1]);
    }
    static int bsc(int[] arr,int t,boolean isfirst){
        int start=0;
        int ans=-1;
        int end=arr.length-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(arr[mid]==t)
            {
                ans=mid;
                if(isfirst)
                end=mid-1;
                else
                start=mid+1;
            }
            else if(arr[mid]<t)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
}
