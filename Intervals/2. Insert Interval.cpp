#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while (i < n and intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i += 1;
        }
        
        while (i < n and intervals[i][0] <= newInterval[1]) {
            if (intervals[i][0] < newInterval[0]) {
                newInterval[0] = intervals[i][0];
            }
            if (intervals[i][1] > newInterval[1]) {
                newInterval[1] = intervals[i][1];
            }
            i += 1;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            i += 1;
        }

        return res;
    }
};

int main() { return 0; }