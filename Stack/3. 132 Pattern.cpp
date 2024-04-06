#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        stack<pair<int, int>> st;
        int minLeft = INT_MAX;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] >= st.top().first) {
                st.pop();
            }
            if (!st.empty() && nums[i] < st.top().first && nums[i] > st.top().second) {
                return true;
            }
            st.push({nums[i], minLeft});
            minLeft = min(nums[i], minLeft);
        }
        return false;
        // stack<int> st;
        // int third = INT_MIN;
        // for (int i = n - 1; i >= 0; i--) {
        //     if (nums[i] < third) {
        //         return true;
        //     }
        //     while (!st.empty() && st.top() < nums[i]) {
        //         third = st.top();
        //         st.pop();
        //     }
        //     st.push(nums[i]);
        // }
        // return false;
    }
};

int main() {
    return 0;
}