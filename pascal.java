// soving through factorial function
import java.util.*;
class Pascal {
    public List<List<Integer>> generate(int numRows) {

        List myList = new ArrayList();
        if(numRows == 0){
           return myList;
        }
        else{
        Pascal ob = new Pascal();

        double z,k,x,y;


         for (int i=0;i<numRows;i++){
             List<Integer> li = new <Integer>ArrayList();
              z = ob.factorial(i);
             for(int j=0;j<=i;j++){


                 k = ob.factorial(j);
                 x = ob.factorial(i-j);
                 y = k*x;
                 li.add((int)(z/y));
             }
             myList.add(li);
         }


           return myList;
        }


    }
    double factorial(double m){
        if(m == 0)
            return 1;
        else
            return (m*factorial(m-1));
    }

    public static void main(String atgs[]){
        Pascal ob1 = new Pascal();
        System.out.println(ob1.generate(23));
    }

}


