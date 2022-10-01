import java.util.Scanner;

public class Insertion {
    public static int[] getArray(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Array size: ");
        String s = sc.nextLine();
        int size = Integer.parseInt(s);
        int[] ar = new int[size];
        System.out.print("Enter Array elements: ");
        s = sc.nextLine() + " ";
        int index = 0;
        String num = s.charAt(0) + "";
        for(int x=1; x<s.length(); x++){
            if(s.charAt(x-1) != ' ' && s.charAt(x) == ' '){
                ar[index] = Integer.parseInt(num);
                index ++;
                num = "";
            }
            else if (s.charAt(x) != ' '){
                num += s.charAt(x);
            }
        }
        return ar;
    }

    public static void displayArray(int[] ar){
        for(int x=0; x<ar.length; x++){
            System.out.print(ar[x] + "\t");
        }
        System.out.println();
    }

    public static int[] insertionSort(int[] ar, boolean reverse){
        int[] sortedAr = new int[ar.length];
        if(!reverse) {
            for (int x = 1; x < ar.length; x++) {
                for (int y = x; y > 0; y--) {
                    if (ar[y] < ar[y - 1]) {
                        int temp = ar[y];
                        ar[y] = ar[y - 1];
                        ar[y - 1] = temp;
                    }
                }
            }
        }
        else{
            for (int x = 1; x < ar.length; x++) {
                for (int y = x; y > 0; y--) {
                    if (ar[y] > ar[y - 1]) {
                        int temp = ar[y];
                        ar[y] = ar[y - 1];
                        ar[y - 1] = temp;
                    }
                }
            }
        }
        return ar;
    }

    public static void main(String[] args){
        int[] ar = getArray();
        displayArray(ar);
        System.out.println("\nSorted Arrays: ");
        System.out.print("Sorted Array:\t");
        displayArray(insertionSort(ar, false));
        System.out.print("Reverse Sorted Array:\t");
        displayArray(insertionSort(ar, true));
    }
}
