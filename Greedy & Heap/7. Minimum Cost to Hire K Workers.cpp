#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for (int i = 0; i < n; ++i) {
            workers[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        sort(workers.begin(), workers.end());

        priority_queue<int> pq;
        int sumQuality = 0;
        double res = DBL_MAX;

        for (auto worker : workers) {
            int quality = worker.second;
            double ratio = worker.first;
            pq.push(quality);
            sumQuality += quality;

            if (pq.size() > k) {
                sumQuality -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = min(res, ratio * sumQuality);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}