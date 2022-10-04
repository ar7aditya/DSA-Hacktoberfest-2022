
// enter the size 'n' of a nxn chess board 
// and given a knight which is placed initially at (0,0) we print all possible move combinations on the board such that the knight is able to 
// travel the board completely without visiting any cell twice

import java.util.Scanner;

public class KnightsTour {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] chess = new int[n][n];

        printKnightsTour(chess, 0, 0, 1);

        sc.close();
        System.exit(0);
    }

    private static void printKnightsTour(int[][] chess, int x, int y, int count) {

        if (x < 0 || y < 0 || x >= chess.length || y >= chess[0].length) {
            return;
        }

        int n = chess.length;
        if (count > n * n) {
            return;
        }

        if (chess[x][y] != 0) {
            return;
        }

        chess[x][y] = count;

        if (count == n * n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(chess[i][j] + "\t");

                }
                System.out.println();

            }
            System.out.println();
        }

        printKnightsTour(chess, x - 2, y + 1, count + 1);
        printKnightsTour(chess, x - 1, y + 2, count + 1);
        printKnightsTour(chess, x + 1, y + 2, count + 1);
        printKnightsTour(chess, x + 2, y + 1, count + 1);
        printKnightsTour(chess, x + 2, y - 1, count + 1);
        printKnightsTour(chess, x + 1, y - 2, count + 1);
        printKnightsTour(chess, x - 1, y - 2, count + 1);
        printKnightsTour(chess, x - 2, y - 1, count + 1);

        chess[x][y] = 0;

    }

}
