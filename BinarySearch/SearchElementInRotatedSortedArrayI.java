package BinarySearch;

import java.util.*;

class Solution {
    public static int search(ArrayList<Integer> arr, int n, int k) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) == k) {
                return mid;
            } else if (arr.get(left) <= arr.get(mid)) {
                if (arr.get(left) <= k && arr.get(mid) >= k) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (arr.get(mid) <= k && arr.get(right) >= k) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
}

public class SearchElementInRotatedSortedArrayI {

}
