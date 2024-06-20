import java.io.*;
import java.util.*;

class Solution {
    private boolean isPossible(int[] position, int m, int distance) {
        int count = 1;
        int lastPos = position[0];
        for (int i = 0; i < position.length; i++) {
            if (position[i] - lastPos >= distance) {
                count++;
                lastPos = position[i];
            }
        }
        return count >= m;
    }

    public int maxDistance(int[] position, int m) {
        int n = position.length;
        Arrays.sort(position);
        int left = 0, right = position[n - 1];
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(position, m, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
}