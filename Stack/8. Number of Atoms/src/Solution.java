import java.util.*;

class Solution {
    public String countOfAtoms(String formula) {
        Stack<Map<String, Integer>> st = new Stack<>();
        int i = 0;
        int n = formula.length();
        while (i < n) {
            char c = formula.charAt(i);
            if (c == '(') {
                st.add(new HashMap<String, Integer>());
                i++;
            } else if (c == ')') {
                var current = st.pop();
                i++;
                int start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    i++;
                }
                String numStr = formula.substring(start, i);
                int multiplier = numStr.length() == 0 ? 1 : Integer.parseInt(numStr);
                for (var entry : current.entrySet()) {
                    String atom = entry.getKey();
                    int count = entry.getValue();
                    int newCount = st.peek().getOrDefault(atom, 0) + count * multiplier;
                    st.peek().put(atom, newCount);
                }
            } else {
                int start = i;
                i++;
                while (i < n && Character.isLowerCase(formula.charAt(i))) {
                    i++;
                }
                String atom = formula.substring(start, i);
                start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    i++;
                }
                String numStr = formula.substring(start, i);
                int count = numStr.length() == 0 ? 1 : Integer.parseInt(numStr);
                int newCount = st.peek().getOrDefault(atom, 0) + count;
                st.peek().put(atom, newCount);
            }
        }
        Map<String, Integer> finalCounts = st.pop();
        StringBuilder sb = new StringBuilder();
        for (var entry : finalCounts.entrySet()) {
            String atom = entry.getKey();
            int count = entry.getValue();
            sb.append(atom);
            if (count > 1)
                sb.append(count);
        }
        return sb.toString();
    }
}