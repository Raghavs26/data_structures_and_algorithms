#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
    }
};


class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;
        int sum = 0, rem = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rem = sum % k;
            if (rem == 0) res++;
            if (rem < 0) rem = -1 * rem;
            if (mp.find(rem) != mp.end()) {
                res += mp[rem];
            }
            mp[rem]++;
        }
        return res;
    }
};

int main() {
    return 0;
}