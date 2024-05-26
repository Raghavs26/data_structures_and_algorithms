#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    unordered_map<int, int> mp;

   private:
    void solve(vector<int> &nums, int i, int k, int &res) {
        if (i == nums.size()) {
            res++;
            return;
        }

        solve(nums, i + 1, k, res);

        if (mp[nums[i] - k] == 0 && mp[nums[i] + k] == 0) {
            mp[nums[i]]++;
            solve(nums, i + 1, k, res);
            mp[nums[i]]--;
        }
    }

   public:
    int beautifulSubsets(vector<int> &nums, int k) {
        int res = 0;
        solve(nums, 0, k, res);
        return res - 1;
    }
};

int main() {
    return 0;
}