//This algorithm can be used at the place where we need to find the element with the representation or to wethere there is any element is repeating more then once.
//Approach Moores Voting Algorithm

public class MooresVotingAlgorithm {
    
    public int majorityElement(int[] nums) {
        int count = 0;
        int majorityElement = nums[0];
        for(int x:nums){
            if(x!=majorityElement){
                count--;
            }
             else{
                count++;
            }
                if(count==0){
                majorityElement= x;
                count=1;
            }
         }
        return majorityElement;
    }
}
