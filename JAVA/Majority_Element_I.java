package JAVA;

//Find the Majority Element that occurs more than N/2 times
//https://leetcode.com/problems/majority-element/

public class Majority_Element_I {
    public int majorityElement(int[] nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate)
                count += 1;
            else count -= 1;
        }

        return candidate;
    }
}
