#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        int i = 0, n = formula.size();
        st.push(map<string, int>());
        while (i < n) {
            char c = formula[i];
            if (c == '(') {
                st.push(map<string, int>());
                i++;
            } else if (c == ')') {
                map<string, int> current = st.top();
                st.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                string numString = formula.substr(start, i - start);
                int multiplier = numString.size() == 0 ? 1 : stoi(numString);
                for (auto [atom, count] : current) {
                    st.top()[atom] += (count * multiplier);
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                string numString = formula.substr(start, i - start);
                int count = numString.size() == 0 ? 1 : stoi(numString);
                st.top()[atom] += count;
            }
        }
        map<string, int> count = st.top();
        string res;
        for (auto [atom, count] : count) {
            res += atom;
            if (count > 1) {
                string temp = to_string(count);
                res += temp;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}