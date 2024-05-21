#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    int findCrossOver(vector<int>& arr, int left, int right, int x) {
        if (arr[right] <= x) {
            return right;
        }
        if (arr[left] > x) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        }
        if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, right, x);
        }
        return findCrossOver(arr, left, mid - 1, x);
    }

   public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int idx1 = findCrossOver(arr, 0, n - 1, x);
        int idx2 = idx1 + 1;
        if (arr[idx1] == x) {
            idx1--;
        }

        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            if (idx1 >= 0 && idx2 < n) {
                int val1 = x - arr[idx1];
                int val2 = arr[idx2] - x;
                if (val1 < val2) {
                    res[i] = arr[idx1];
                    idx1--;
                } else {
                    res[i] = arr[idx2];
                    idx2++;
                }
            } else if (idx1 >= 0) {
                res[i] = arr[idx1];
                idx1--;
            } else {
                res[i] = arr[idx2];
                idx2++;
            }
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        priority_queue<pair<int, int> > pq;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (arr[i] - x == 0) continue;
            pq.push({abs(arr[i] - x), -arr[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res.push_back(-pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}