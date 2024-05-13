#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }
        vector<int> res;
        int n = s.length();
        int wordLength = words[0].size();
        int totalLength = wordLength * words.size();
        for (int i = 0; i < n - totalLength + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            while (j < words.size()) {
                string word = s.substr(i + j * wordLength, wordLength);
                if (mp.find(word) != mp.end()) {
                    seen[word]++;
                    if (seen[word] > mp[word]) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == words.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        int n = s.size(), num = words.size(), len = words[0].size();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                } else
                    break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};
int main() {
    return 0;
}