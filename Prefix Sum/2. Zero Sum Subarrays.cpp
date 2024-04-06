#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define lli long long int

class Solution {
   public:
    long long int findSubarray(vector<long long int> &arr, int n) {
        unordered_map<lli, lli> mp;
        lli curSum = 0;
        lli res = 0;
        for (auto i : arr) {
            curSum += i;
            if (curSum == 0) res++;
            if (mp.find(curSum - 0) != mp.end()) res += mp[curSum - 0];
            mp[curSum]++;
        }
        return res;
    }
};

int main() {
    return 0;
}