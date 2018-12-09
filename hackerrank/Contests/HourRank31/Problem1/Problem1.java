import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

//https://www.hackerrank.com/contests/hourrank-31/challenges/hanging-posters/problem

class Result {
    public static int solve(int h, List<Integer> wallPoints, List<Integer> lengths) {
        int ladderL = 0;
        for (int c=0; c<lengths.size(); c++) {
            int req = wallPoints.get(c);
            int pos = lengths.get(c);
            double k = (double) (req - pos/4) - h;
            int curr = (int) Math.ceil(k);
            if (ladderL <= curr) {
                ladderL = curr;
            }
        }
        
        return ladderL;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int h = Integer.parseInt(firstMultipleInput[1]);

        String[] wallPointsTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> wallPoints = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int wallPointsItem = Integer.parseInt(wallPointsTemp[i]);
            wallPoints.add(wallPointsItem);
        }

        String[] lengthsTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> lengths = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int lengthsItem = Integer.parseInt(lengthsTemp[i]);
            lengths.add(lengthsItem);
        }

        int answer = Result.solve(h, wallPoints, lengths);

        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
