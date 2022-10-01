/*
question link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
We have to arrange the elements of the givne array such that :
  1. Every consecutive pair of integers have opposite signs.
  2. For all integers with the same sign, the order in which they were present in nums is preserved.
  3. The rearranged array begins with a positive integer.
*/

// SOLUTION:


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int Size_of_array= nums.size();
        vector<int> Answer_array(Size_of_array);
        int i=0,j=1;
        for(int k=0;k<Size_of_array;k++){
            if( nums[k] > 0 ){
                Answer_array[i] = nums[k];
                i+=2;
            }
            else{
                Answer_array[j] = nums[k];
                j+=2;
            }
        }
        return Answer_array;
    }
};
