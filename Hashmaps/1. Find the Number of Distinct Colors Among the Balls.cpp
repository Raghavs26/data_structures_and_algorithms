#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_set<int> distinctColors;
        vector<int> res;
        for (auto query : queries) {
            int ball = query[0], color = query[1];
            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                bool colorExists = false;
                for (auto [b, c] : ballColor) {
                    if (c == oldColor && b != ball) {
                        colorExists = true;
                        break;
                    }
                }
                if (!colorExists) distinctColors.erase(oldColor);
            }
            ballColor[ball] = color;
            distinctColors.insert(color);
            res.push_back(distinctColors.size());
        }
        return res;
    }
};

int main() {
    return 0;
}