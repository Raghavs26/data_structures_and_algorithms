#include <bits/stdc++.h>
using namespace std;

struct Robot {
    int position;
    int health;
    char direction;
};

class Solution {
   public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[positions[i]] = i;
            robots.push_back({positions[i], healths[i], directions[i]});
        }
        sort(robots.begin(), robots.end(), [&](const Robot& r1, const Robot& r2) {
            return r1.position < r2.position;
        });

        stack<Robot> st;

        for (int i = 0; i < n; i++) {
            if (robots[i].direction == 'R') {
                st.push(robots[i]);
            } else {
                while (!st.empty() && st.top().direction == 'R') {
                    if (st.top().health > robots[i].health) {
                        st.top().health -= 1;
                        robots[i].health = 0;
                        break;
                    } else if (st.top().health < robots[i].health) {
                        robots[i].health -= 1;
                        st.pop();
                    } else {
                        st.pop();
                        robots[i].health = 0;
                        break;
                    }
                }
                if (robots[i].health) {
                    st.push(robots[i]);
                }
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top().health);
            st.pop();
        }
        return res;
    }
};
int main() {
    return 0;
}