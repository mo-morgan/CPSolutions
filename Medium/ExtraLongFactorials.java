//https://www.hackerrank.com/challenges/extra-long-factorials/submissions

//Java's built-in BigInteger class allows for a simple solution.
//Will need to develop a pattern for storing elements(or design a BigInteger class) if using C/C++

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static void extraLongFactorials(int n) {
        BigInteger c = new BigInteger(Integer.toString(n));

        BigInteger ans = factorial(c);
        System.out.println(ans);
    }

    static BigInteger factorial(BigInteger c) {
        if (c.intValue() == 1) {
            return c;
        }

        return c.multiply(factorial(BigInteger.valueOf(c.intValue()-1)));
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
