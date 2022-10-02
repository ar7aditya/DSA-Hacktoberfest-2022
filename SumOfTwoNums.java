import java.util.Scanner;

public class SumOfTwoNums {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        Scanner input = new Scanner(System.in);
        System.out.print("input two integers: ");
        int a = input.nextInt();
        int b = input.nextInt();
        int sum = a+b;
        System.out.println("Sum of the given numbers is "+sum);
    }
}
