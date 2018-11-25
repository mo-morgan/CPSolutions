//https://www.hackerrank.com/challenges/xor-matrix/problem


//Naive attempt (4.02/50.0):
//	1. Constraint requires > 10^19
//	2. O(n^2) complexity too slow

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {
    static int[] xorMatrix(int m, int[] first_row) {

        int[] prevRow = first_row;
        int[] nextRow = new int[first_row.length];
        for (int i = 0; i < m-1; i++) {
            for (int c = 0; c < first_row.length; c++) {
                if (c == first_row.length - 1) {
                    nextRow[c] = prevRow[c] ^ prevRow[0];
                } else {
                    nextRow[c] = prevRow[c] ^ prevRow[c + 1];
                }
                System.out.print(nextRow[c] + " ");

            }
            System.out.println();
            prevRow = nextRow;
            nextRow = new int[first_row.length];
        }

        return prevRow;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0].trim());

        int m = Integer.parseInt(nm[1].trim());

        int[] first_row = new int[n];

        String[] first_rowItems = scanner.nextLine().split(" ");

        for (int first_rowItr = 0; first_rowItr < n; first_rowItr++) {
            int first_rowItem = Integer.parseInt(first_rowItems[first_rowItr].trim());
            first_row[first_rowItr] = first_rowItem;
        }

        int[] result = xorMatrix(m, first_row);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bufferedWriter.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
