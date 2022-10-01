import java.io.*;
import java.util.*;

public class palindromeStr {

    static boolean isPalindrome(String A) {
        
        int size=A.length()-1;
        int i=0;
       while(size>i)
       {
              if(A.charAt(i)!=A.charAt(size))
                  return false;
                  i++;
                  size--;
       }
                return true;  
          }
       

        public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
 
        if (isPalindrome(A))
            System.out.print("Yes");
        else
            System.out.print("No");
    }
    }

// new thing learned ---> charAt
//                   ---> how to use boolean func


