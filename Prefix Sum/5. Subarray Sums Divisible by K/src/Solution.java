import java.io.*;
import java.util.*;

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int res = 0;
        for (int num : nums) {
            int rem = num % k;
            if (rem == 0)
                res++;
            if (rem < 0)
                rem += k;
            if (mp.containsKey(rem)) {
                res += mp.get(rem);
            }
            mp.put(rem, mp.getOrDefault(rem, 0) + 1);
        }
        return res;
    }
}