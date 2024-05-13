#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define long long int lli;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp{0, 1};
        int sum = 0;
        int res = 0;
        for (int num : nums) {
            sum += num;
            if (sum == k) res++;
            if (mp.find(sum - k) != mp.end()) res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};

int main() {
    return 0;
}