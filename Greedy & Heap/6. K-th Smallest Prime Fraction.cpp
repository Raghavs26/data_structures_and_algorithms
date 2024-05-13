#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    typedef pair<double, vector<int>> DoubleVectorPair;

   public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<DoubleVectorPair, vector<DoubleVectorPair>, greater<DoubleVectorPair>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({(double)arr[i] / arr.back(), {i, n - 1}});
        }
        while (k > 1) {
            auto p = pq.top();
            pq.pop();

            int i = p.second[0];
            int j = p.second[1] - 1;

            pq.push({(double)arr[i] / arr[j], {i, j}});
            k--;
        }

        return {arr[pq.top().second[0]], arr[pq.top().second[1]]};
    }
};

int main() {
    return 0;
}

int main() {
    return 0;
}