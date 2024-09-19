#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<int> solve(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
                vector<int> left = solve(expression.substr(0, i));
                vector<int> right = solve(expression.substr(i + 1));
                for (int x : left) {
                    for (int y : right) {
                        if (expression[i] == '+') res.push_back(x + y);
                        if (expression[i] == '-') res.push_back(x - y);
                        if (expression[i] == '*') res.push_back(x * y);
                    }
                }
            }
        }
        if (res.size() == 0) res.push_back(stoi(expression));
        return res;
    }

   public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};

int main() {
    return 0;
}