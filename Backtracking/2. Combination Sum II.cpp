#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    void solve(vector<int>& arr, vector<int>& temp, int k, int i, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j - 1]) continue;
            if (k - arr[j] < 0) break;
            temp.push_back(arr[j]);
            solve(arr, temp, k - arr[j], j + 1, res);
            temp.pop_back();
        }
    }

   public:
    vector<vector<int>> CombinationSum2(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(arr, temp, k, 0, res);
        return res;
    }
};

int main() {
    return 0;
}
