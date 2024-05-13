#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int windowStart = 0, windowEnd = 0;
        int res = 0;
        while (windowEnd < n) {
            int rightElement = nums[windowEnd];
            mp[rightElement]++;
            while (mp[rightElement] > k) {
                int leftElement = nums[windowStart];
                mp[leftElement]--;
                windowStart++;
            }
            res = max(res, windowEnd - windowStart + 1);
            windowEnd++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 2, 3, 1, 2, 3, 1, 2};
    s.maxSubarrayLength(v, 2);
    return 0;
}