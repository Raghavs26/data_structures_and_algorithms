#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(int n, vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (asteroids[i] < 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && asteroids[i] > abs(st.top())) {
                    st.pop();
                }
                if (!st.empty() && asteroids[i] == abs(st.top())) {
                    st.pop();
                } else if (st.empty()) {
                    res.push_back(asteroids[i]);
                }
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
   public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long int res = 0;
        int n = nums.size();
        int prev = -1;

        int windowStart = 0, windowEnd = 0;
        while (windowEnd < n) {
            if (prev != nums[windowEnd]) {
                prev = nums[windowEnd];
                res = windowEnd - windowStart + 1;
            } else {
                windowStart = windowEnd;
            }
            windowEnd++;
        }
        return res;
    }
};

int main() {
    vector<int> v{8, 4, 2, 9, -7};
    return 0;
}