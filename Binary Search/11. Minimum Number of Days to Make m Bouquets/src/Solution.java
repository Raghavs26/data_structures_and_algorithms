import java.io.*;
import java.util.*;

class Solution {
    private boolean isPossible(int[] bloomDay, int m, int k, int days) {
        int length = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= days) {
                length++;
            } else {
                length = 0;
            }
            if (length == k) {
                bouquets++;
                length = 0;
            }
        }
        return bouquets >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        if (m * k > bloomDay.length)
            return -1;
        int res = -1;
        int start = Integer.MAX_VALUE, end = Integer.MIN_VALUE;
        for (int i = 0; i < bloomDay.length; i++) {
            start = Math.min(start, bloomDay[i]);
            end = Math.max(end, bloomDay[i]);
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                res = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return res;
    }
}