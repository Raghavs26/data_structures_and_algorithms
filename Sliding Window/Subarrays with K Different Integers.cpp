#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int leftFar = 0, leftNear = 0;
        int res = 0;
        for (int right : nums) {
            mp[right]++;
            while (mp.size() > k) {
                mp[nums[leftNear]]--;
                if (mp[nums[leftNear]] == 0) {
                    mp.erase(nums[leftNear]);
                }
                leftNear++;
                leftFar = leftNear;
            }
            while (mp[nums[leftNear]] > 1) {
                mp[nums[leftNear]]--;
                leftNear++;
            }

            if (mp.size() == k) {
                res += (leftNear - leftFar + 1);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}