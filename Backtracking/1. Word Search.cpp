#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    bool solve(vector<vector<char>>& board, string word, int x, int y, int i) {
        if (i == word.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || word[i] != board[x][y]) {
            return false;
        }
        char ch = board[x][y];
        board[x][y] = ' ';
        bool a = solve(board, word, x + 1, y, i + 1);
        bool b = solve(board, word, x - 1, y, i + 1);
        bool c = solve(board, word, x, y + 1, i + 1);
        bool d = solve(board, word, x, y - 1, i + 1);
        board[x][y] = ch;
        return a || b || c || d;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    if (solve(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main() {
    return 0;
}