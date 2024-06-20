import java.io.*;
import java.util.*;

class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = profit.length, m = worker.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i = 0; i < n; i++) {
            pq.add(new int[] { difficulty[i], profit[i] });
        }
        Arrays.sort(worker);
        int res = 0;
        int i = m - 1;
        while (i >= 0 && !pq.isEmpty()) {
            if (pq.peek()[0] > worker[i]) {
                pq.poll();
            } else {
                res += pq.peek()[1];
                i--;
            }
        }
        return res;
    }
}