import java.io.*;
import java.util.*;

public class HouseRobber {
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int numHouses = scn.nextInt();
        int[] houses = new int[numHouses];

        // Take input of money stashed in each house
        for(int i=0;i<numHouses;i++){
            houses[i] = scn.nextInt();
        }
        System.out.println("Value Robbed: ");
        System.out.println(houseRobberDP(houses, numHouses));
    }
    public static int houseRobberDP(int[] houses, int numHouses){
       int[] dp = new int[numHouses];
       dp[0] = houses[0];
       for(int i=1;i<numHouses;i++){
        if(i>=2){
            // Rob ith house.
            dp[i] = houses[i] + dp[i-2];
        }
        // skip ith house.
        dp[i] = Math.max(dp[i], dp[i-1]);

       }
       return dp[numHouses-1];

    }
    public static int houseRobberRecursive(int[] houses, int currHouseNum, int numHouses){
        if(currHouseNum >= numHouses){
            return 0;
        }
        // Rob current house and skip the next.
        int robCurrent = houses[currHouseNum] + houseRobberRecursive(houses, currHouseNum+2, numHouses);
        // Skip current house and move to next.
        int skipCurrent = houseRobberRecursive(houses, currHouseNum+1, numHouses);
        return Math.max(robCurrent, skipCurrent);
    }
}
