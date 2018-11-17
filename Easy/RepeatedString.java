//https://www.hackerrank.com/challenges/repeated-string/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static long repeatedString(String s, long n) {
        long numAs = 0;
        if (n < s.length()) {
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == 'a')
                    numAs++;
            }
            return numAs;
        }

        long lastStringLength = n % s.length();  // to get the last substring we care about

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a')
                numAs++;
        }

        int numAsInLastString = 0;
        for (int i = 0; i < lastStringLength; i++) {
            if (s.charAt(i) == 'a')
                numAsInLastString++;
        }

        long k = (long) Math.floor(n / s.length());

        return numAs * k + numAsInLastString;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        long n = scanner.nextLong();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long result = repeatedString(s, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
