import java.util.Arrays;

public class SearchInSortedRowColMatrix {
    public static void main(String[] args) {
        int[][] arr = {
                {1,3,5,7},
                {10,11,16,20},
                {23,30,34,60}
        }; //sorted row wise and column wise
        System.out.println(Arrays.toString(search(arr,7)));
    }

    private static int[] search(int[][] matrix, int target) {
        int row = 0, col = matrix[0].length - 1;
        while (row < matrix.length && col>=0){
            if(matrix[row][col]==target)
                return new int[] {row,col};
            if (matrix[row][col]<target)
                row++;
            else
                col--;
        }
        return new int[] {-1,-1};
    }
}
