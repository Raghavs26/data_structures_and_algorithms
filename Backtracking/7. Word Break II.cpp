#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    string join(vector<string>& str) {
        string res;
        for (int i = 0; i < str.size(); i++) {
            res += str[i];
            if (i != str.size() - 1) res += " ";
        }
        return res;
    }

    void solve(string& s, unordered_set<string>& words, int i, vector<string> current, vector<string>& res) {
        if (i == s.size()) {
            res.push_back(join(current));
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string currentWord = s.substr(i, j - i + 1);
            if (words.find(currentWord) != words.end()) {
                current.push_back(currentWord);
                solve(s, words, j + 1, current, res);
                current.pop_back();
            }
        }
    }

   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> current, res;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        solve(s, words, 0, current, res);
        return res;
    }
};

int main() {
    return 0;
}
