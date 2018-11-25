//https://www.hackerrank.com/challenges/2d-array/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int hourglassSum(int[][] arr) {
        int max = arr[0][0] + arr[0][1] + arr[0][2]
                                   + arr[1][1]
                        + arr[2][0] + arr[2][1] + arr[2][2];

        for (int i = 0; i < arr.length - 2; i++) {
            for (int c = 0; c < arr[0].length; c++) {
                if (c + 2 >= arr[0].length) {
                    break;
                }
                
                int sum = arr[i][c] + arr[i][c+1] + arr[i][c+2]
                                   + arr[i+1][c+1]
                        + arr[i+2][c] + arr[i+2][c+1] + arr[i+2][c+2];

                if (sum >= max) {
                    max = sum;
                }
            }

        }
        return max;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
