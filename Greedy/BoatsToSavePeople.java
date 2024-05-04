package Greedy;

import java.util.Arrays;

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int n = people.length;
        Arrays.sort(people);
        int boats = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int weight = people[left] + people[right];
            if (weight <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
}

public class BoatsToSavePeople {

}
