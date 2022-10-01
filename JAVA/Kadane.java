// Java program to print largest contiguous array sum using Kadane's Algorithm

import java.util.*;

public class Kadane
{
	public static void main (String[] args)
	{
        // Scanner to take user input
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no of elements");
        int n=sc.nextInt();
        int array[]= new int[n];
        // Input elements from user
        for(int i=0;i<n;i++){
            array[i]=sc.nextInt();
        }		
		System.out.println("Maximum contiguous sum is " + maxSubArraySum(array));
        sc.close();
	}

	static int maxSubArraySum(int a[])
	{
		int size = a.length;
		int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;

		for (int i = 0; i < size; i++)
		{
			max_ending_here = max_ending_here + a[i];
			if (max_so_far < max_ending_here)
				max_so_far = max_ending_here;
			if (max_ending_here < 0)
				max_ending_here = 0;
		}
		return max_so_far;
	}
}