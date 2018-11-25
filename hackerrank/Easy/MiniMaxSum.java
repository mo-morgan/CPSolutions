//https://www.hackerrank.com/challenges/mini-max-sum/problem

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        long max, min, sum;
        sum = max = min = scanner.nextLong();

        for(int i=1; i<5;i++){
            long temp = scanner.nextLong();
            sum += temp;
            if(max > temp){
                if(min > temp) {
                    min = temp;
                }
            } else {
                max = temp;
            }
        }

        System.out.print((sum - max) + " " + (sum - min));
    }
}

