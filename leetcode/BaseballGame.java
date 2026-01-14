class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> record = new Stack<>();
        for (int i = 0; i < operations.length; i++) {
            String s = operations[i];
            if (s.equals("+")) {
                int last = record.pop();
                int last2 = record.peek();
                record.push(last);
                record.push(last + last2);
            } else if (s.equals("D")) {
                int last = record.peek();
                record.push(last * 2);
            } else if (s.equals("C")) {
                record.pop();
            } else {
                int number = Integer.parseInt(s);
                record.add(number);
            }
        }

        return record.stream().mapToInt(Integer::intValue).sum();
    }
}