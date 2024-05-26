#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    bool canFormWord(string& s, unordered_map<char, int> letterCount) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
            if (letterCount.find(c) == letterCount.end() || mp[c] > letterCount[c]) {
                return false;
            }
        }
        return true;
    }
    int solve(vector<string>& words, int i, unordered_map<char, int>& letterCount, vector<int>& score) {
        if (i == words.size()) {
            return 0;
        }
        int include = 0;
        if (canFormWord(words[i], letterCount)) {
            int currentScore = 0;
            for (char c : words[i]) {
                letterCount[c]--;
                currentScore += score[c - 'a'];
            }
            include = currentScore + solve(words, i + 1, letterCount, score);
            for (char c : words[i]) {
                letterCount[c]++;
            }
        }
        int exclude = solve(words, i + 1, letterCount, score);
        return max(include, exclude);
    }

   public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterCount;
        for (char c : letters) {
            letterCount[c]++;
        }
        return solve(words, 0, letterCount, score);
    }
};

int main() {
    return 0;
}