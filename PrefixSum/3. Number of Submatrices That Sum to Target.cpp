#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int res = 0;
        for (int i = 0; i < col; i++) {
            unordered_map<int, int> mp;
            int sum = 0;
            for (int j = 0; j < row; j++) {
                sum += matrix[j][i];
                if (sum == target) res++;
                if (mp.find(sum - target) != mp.end()) res += mp[sum - target];
                mp[sum]++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}