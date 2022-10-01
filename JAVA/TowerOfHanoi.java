import java.util.Scanner;

public class TowerOfHanoi {
    public static void main(String[] args) {
        int n;        
        // Scanner to get user input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of disks:");
        // Take integer input from user - no of disks
        n = sc.nextInt();
        //Passing values to function
        towerOfHanoi(n, 'A', 'B', 'C');
        sc.close();
    }
    public static void towerOfHanoi(int topN, char source, char auxiliary, char destination) {
        if (topN == 1) {
            System.out.println("Disk 1 from " + source + " to " + destination);
        } else {
            towerOfHanoi(topN - 1, source, destination, auxiliary);
            System.out.println("Disk " + topN + " from " + source + " to " + destination);
            towerOfHanoi(topN - 1, auxiliary, source, destination);
        }
    }
}