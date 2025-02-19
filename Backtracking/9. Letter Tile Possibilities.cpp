#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void solve(string tiles, int index, int &res) {
        if (index > 0) res++;
        for (int i = index; i < tiles.size(); i++) {
            if (i != index && tiles[i] == tiles[index]) continue;
            swap(tiles[index], tiles[i]);
            solve(tiles, index + 1, res);
            swap(tiles[index], tiles[i]);
        }
    }

   public:
    int numTilePossibilities(string tiles) {
        int res = 0;
        sort(tiles.begin(), tiles.end());
        solve(tiles, 0, res);
        return res;
    }
};

int main() {
    return 0;
}