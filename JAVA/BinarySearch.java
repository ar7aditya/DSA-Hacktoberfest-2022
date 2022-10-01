package random;

import java.util.Arrays;

public class BinarySearchDemo {
    
   public static void main(String args[]){
      int[] sourceArray = {1,2,3,4,6,7,9,11,12,14,15,
      16,17,19,33,34,43,45,55,66,76,88};
      System.out.println("Input Array: " +Arrays.toString(sourceArray));
      printline(50);
      // find location of 55 
      int location = find(sourceArray, 55);
      if(location != -1){
         System.out.println("Element found at location: " +(location+1));
      }else {
         System.out.println("Element not found.");
      }    
   }

   public static int find(int[] intArray, int data){
      int lowerBound = 0;
      int upperBound = intArray.length -1;
      int midPoint = -1;
      int comparisons = 0;      
      int index = -1;
      while(lowerBound <= upperBound){
         System.out.println("Comparison " + (comparisons +1) ) ;
         System.out.println("lowerBound : "+lowerBound  
                           + " , intArray[" + lowerBound+"] = " 
                           + intArray[lowerBound]) ;
         System.out.println("upperBound : "+upperBound  
                           + " , intArray[" + upperBound+"] = " 
                           + intArray[upperBound]) ;
         comparisons++;
         // compute the mid point 
         midPoint = (lowerBound + upperBound) / 2;
         // data found
         if(intArray[midPoint] == data){
		    index = midPoint;
            break;
         }
         else {
            // if data is larger 
            if(intArray[midPoint] < data){
               // data is in upper half
               lowerBound = midPoint + 1;
            }
            // data is smaller 
            else{           
               // data is in lower half 
               upperBound = midPoint -1;
            }
         }               
      }
      System.out.println("Total comparisons made: " + comparisons);
      return index;
   }
   
   public static void printline(int count){
      for(int i=0;i <count-1;i++){
         System.out.print("=");
      }
      System.out.println("=");
   }
}
