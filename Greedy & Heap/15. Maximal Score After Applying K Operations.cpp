#include <bits/stdc++.h>
using namespace std;

// time complexity: O(NLogK)
class Solution {
   public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<long long> pq;
        for (int i : nums) pq.push(i);
        while (k--) {
            long long top = pq.top();
            pq.pop();
            res += top;
            pq.push(ceil(top / 3.0));
        }
        return res;
    }
};

int main() {
    return 0;
}