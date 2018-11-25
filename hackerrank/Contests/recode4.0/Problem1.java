//https://www.hackerrank.com/contests/recode-4/challenges/misas-love

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

//Misinterpreted question: instead of finding all substrings of a string and counting all the reoccurances, a much simpler solution would have sufficed
//See https://www.hackerrank.com/contests/recode-4/challenges/misas-love/forum/comments/514583

public class Solution {
    private static Map<String, Integer> occurence = new HashMap<>();
    
    public static void SubString(String str, int n) 
    { 
       for (int i = 0; i < n; i++)  {
           for (int j = i+1; j <= n; j++) {
               String k = str.substring(i,j);
               if(!occurence.containsKey(str.substring(i,j))) {
                   occurence.put(k, 1);
               } else {
                   occurence.put(k, occurence.get(k)+1);
               }
           }
       }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        SubString(s, s.length());
        
        Map.Entry<String, Integer> maxEntry = null;
        for (Map.Entry<String, Integer> entry : occurence.entrySet()) {
            if (maxEntry == null || entry.getValue().compareTo(maxEntry.getValue()) > 0) {
                maxEntry = entry;
            }
        }
        System.out.println(maxEntry.getValue());
    }
}