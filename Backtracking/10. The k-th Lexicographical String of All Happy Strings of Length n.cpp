#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void solve(string current, vector<string>& res, int n) {
        if (current.size() == n) {
            res.push_back(current);
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!current.empty() && current.back() == ch) continue;
            solve(current + ch, res, n);
        }
    }

   public:
    string getHappyString(int n, int k) {
        vector<string> res;
        string current{""};
        solve(current, res, n);
        if (k > res.size()) return "";
        return res[k - 1];
    }
};

int main() {
    return 0;
}