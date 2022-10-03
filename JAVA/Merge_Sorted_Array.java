import java.util.Arrays;

// Link to the problem: https://leetcode.com/problems/merge-sorted-array/

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=0,j=0,k=0;
        int[] temp= Arrays.copyOfRange(nums1, 0, m);
        while(i<m && j<n){
            if(temp[i]<nums2[j]){
                nums1[k]=temp[i];
                i++;
            }else{
                nums1[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<m){
            nums1[k]=temp[i];
            k++;
            i++;
        }
        while(j<n){
            nums1[k]=nums2[j];
            k++;
            j++;
        }
    }
}