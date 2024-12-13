#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool isPossible(vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int num : nums) {
            if (num > penalty) operations += (num - 1) / penalty;
        }
        return operations <= maxOperations;
    }

   public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int res = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, maxOperations, mid)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}