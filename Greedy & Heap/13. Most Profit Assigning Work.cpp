#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({profit[i], difficulty[i]});
        }

        sort(worker.begin(), worker.end());

        int res = 0, i = m - 1;
        while (i >= 0 && !pq.empty()) {
            if (pq.top().second > worker[i]) {
                pq.pop();
            } else {
                res += pq.top().first;
                i--;
            }
        }
        return res;
    }
};
int main() {
    return 0;
}