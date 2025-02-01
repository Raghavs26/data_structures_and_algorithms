#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) -> double {
            return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
        };

        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto currentClass : classes) {
            int pass = currentClass[0], total = currentClass[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        while (extraStudents--) {
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pq.pop();
            pass++;
            total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        double res = 0.0;
        while (!pq.empty()) {
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pq.pop();
            res += (double)pass / total;
        }

        return res / classes.size();
    }
};

int main() {
    return 0;
}