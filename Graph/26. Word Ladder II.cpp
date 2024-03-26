#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            string word = vec.back();
            if (vec.size() > level) {
                level += 1;
                for (auto it : usedOnLevel) {
                    st.erase(it);
                }
            }
            if (word == endWord) {
                if (res.empty()) {
                    res.push_back(vec);
                } else if (res[0].size() == vec.size()) {
                    res.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = originalChar;
            }
        }
        return res;
    }
};

class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        queue<vector<string>> q;

        q.push({beginWord});
        int level = 1;
        int minLevel = INT_MAX;

        unordered_set<string> visited;

        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();
            if (path.size() > level) {
                for (string s : visited) st.erase(s);
                visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            string word = path.back();
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (st.find(word) != st.end()) {
                        vector<string> newpath = path;
                        newpath.push_back(word);
                        visited.insert(word);
                        if (word == endWord) {
                            minLevel = level;
                            res.push_back(newpath);
                        } else {
                            q.push(newpath);
                        }
                    }
                }
                word[i] = original;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}