#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Interval {
    int start = 0, end = 0;
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    vector<vector<int>> dp;

   private:
    int solve(int n, int m, int a[], int b[]) {
        if (m == 0) return 0;
        if (n < m) return INT_MIN;
        if (dp[n][m] != INT_MIN) return dp[n][m];

        int include = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b);
        int exclude = solve(n - 1, m, a, b);

        return dp[n][m] = max(exclude, include);
    }

   public:
    int maxDotProduct(int n, int m, int a[], int b[]) {
        dp.resize(n + 1, vector<int>(m + 1, INT_MIN));
        return solve(n, m, a, b);
    }
};

class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[i][0], e2 = secondList[i][1];

            if ((s1 >= s2 && s1 <= e2) || (s2 >= s1 && s2 <= e1)) {
                int start = max(s1, s2);
                int end = min(e1, e2);
                res.push_back({start, end});
            }

            if (e1 < e2) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

class Solution {
   public:
    int maxDotProduct(int n, int m, int a[], int b[]) {
        sort(a, a + n);
        sort(b, b + n);
        int start = abs(n - m);
        int end = max(n, m);
        int res = 0;
        while (start < end) {
            res += a[start] * b[start];
            start++;
        }
        return res;
    }
};

class Solution {
   public:
    vector<Interval> merge(const vector<Interval>& arr1, const vector<Interval>& arr2) {
        vector<Interval> res;
        int n = arr1.size(), m = arr2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int s1 = arr1[i].start, e1 = arr1[i].end;
            int s2 = arr2[j].start, e2 = arr2[j].end;

            if ((s1 >= s2 && s1 <= e2) || (s2 >= s1 && s2 <= e1)) {
                int start = max(s1, s2);
                int end = min(e1, e2);
                res.push_back({start, end});
            }

            if (e1 < e2) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    // vector<Interval> v1{{1, 3}, {5, 6}, {7, 9}};
    // vector<Interval> v2{{2, 3}, {5, 7}};
    vector<Interval> v1{{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<Interval> v2{{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    auto res = s.merge(v1, v2);
    for (auto i : res) {
        cout << "(" << i.start << "," << i.end << ")" << endl;
    }
    return 0;
}