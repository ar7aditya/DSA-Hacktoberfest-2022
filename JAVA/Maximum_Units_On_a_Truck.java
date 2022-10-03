import java.util.Arrays;

// Link to the problem:https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
//         Using this instead of comparator to sort boxTypes[i][] in decreasing fashion
        Arrays.sort(boxTypes, (x,y) -> Integer.compare(y[1], x[1]));
        int ans=0;
        for(int[] row: boxTypes){
            int min=Math.min(truckSize,row[0]);
            ans+=min*row[1];
            truckSize-=min;
            if(truckSize==0) break;
        }
        return ans;
    }
}
