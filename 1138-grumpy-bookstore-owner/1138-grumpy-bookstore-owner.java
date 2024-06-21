class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;
        int windowStart = 0, windowEnd = 0;
        int additionalSatisfied = 0, alwaysSatisfied = 0;
        int maxAdditionalSatisfied = 0;

        while (windowEnd < n) {
            if (grumpy[windowEnd] == 1) {
                additionalSatisfied += customers[windowEnd];
            } else {
                alwaysSatisfied += customers[windowEnd];
            }
            if (windowEnd - windowStart + 1 > minutes) {
                if (grumpy[windowStart] == 1) {
                    additionalSatisfied -= customers[windowStart];
                }
                windowStart++;
            }
            maxAdditionalSatisfied = Math.max(additionalSatisfied, maxAdditionalSatisfied);
            windowEnd++;
        }
        return alwaysSatisfied + maxAdditionalSatisfied;
    }
}