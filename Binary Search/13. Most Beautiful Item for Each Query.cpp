#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());

        vector<int> res(n, 0);
        res[0] = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            res[i] = max(res[i - 1], items[i][1]);
        }

        vector<int> result;
        for (int query : queries) {
            auto it = upper_bound(items.begin(), items.end(), vector<int>{query, INT_MAX});
            int index = it - items.begin() - 1;

            if (index >= 0) {
                result.push_back(res[index]);
            } else {
                result.push_back(0);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}