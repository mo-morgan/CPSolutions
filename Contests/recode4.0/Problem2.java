//https://www.hackerrank.com/contests/recode-4/challenges/ls-meal/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

//Timeout on 3 test cases: needed to find a better solution in O(n)

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        char[] k = s.toCharArray();
        int countc = 0;
        int posp = -1, posc = -1;
        for (int i = 0; i < k.length; i++) {
            if (k[i] == 'p') {
                posp = i;
            }
            if (k[i] == 'c' && countc == 0) {
                posc = i;
                countc = 1;
            }
        }
        int count = 0;
        if (posc != -1 && posp != -1 && posc < posp) {
            char temp = k[posp];
            k[posp] = k[posc];
            k[posc] = temp;
            for (int i = 0; i < k.length; i++) {
                if (k[i] == 'c') { // want to count c's before p
                    for (int j = i + 1; j < k.length; j++) {
                        if (k[j] == 'p') {
                            count++;
                        }
                    }
                } else {
                    for (int j = 0; j < i; j++) {
                        if (k[j] == 'c') {
                            count++;
                        }
                    }
                }
            }
        }
        System.out.println(count);
    }
}