#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0, res = 0;
        unordered_map<int, int> mp;
        for (int num : nums) {
            sum += num;
            if (sum == goal) res++;
            if (mp.count(sum - goal)) res += mp[sum - goal];
            mp[sum]++;
        }
        return res;
    }
};

int main() {
    return 0;
}