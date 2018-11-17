//https://www.hackerrank.com/challenges/magic-square-forming/submissions

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    static int formingMagicSquare(int[][] s) {
        int[] cost = {0,0,0,0,0,0,0,0};
        int allMS[][] = 
        {
            {4,9,2,3,5,7,8,1,6},
            {4,3,8,9,5,1,2,7,6},
            {2,9,4,7,5,3,6,1,8},
            {2,7,6,9,5,1,4,3,8},
            {8,1,6,3,5,7,4,9,2},
            {8,3,4,1,5,9,6,7,2},
            {6,7,2,1,5,9,8,3,4},
            {6,1,8,7,5,3,2,9,4},
        };
        for (int c = 0; c < 8; c++) {
            cost[c] = Math.abs(s[0][0] - allMS[c][0]) + Math.abs(s[0][1] - allMS[c][1])
            + Math.abs(s[0][2] - allMS[c][2]);
            cost[c] += Math.abs(s[1][0] - allMS[c][3]) + Math.abs(s[1][1] - allMS[c][4])
            + Math.abs(s[1][2] - allMS[c][5]);
            cost[c] += Math.abs(s[2][0] - allMS[c][6]) + Math.abs(s[2][1] - allMS[c][7])
            + Math.abs(s[2][2] - allMS[c][8]);
        }

        Arrays.sort(cost);
        return cost[0];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] s = new int[3][3];

        for (int i = 0; i < 3; i++) {
            String[] sRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int sItem = Integer.parseInt(sRowItems[j]);
                s[i][j] = sItem;
            }
        }

        int result = formingMagicSquare(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
