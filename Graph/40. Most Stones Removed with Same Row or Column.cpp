#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N^2)
// space complexity: O(N)
class Solution {
   private:
    void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited) {
        visited[index] = true;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] &&
                ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                dfs(stones, i, visited);
            }
        }
    }

   public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int connected = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(stones, i, visited);
            connected++;
        }
        return n - connected;
    }
};

int main() {
    return 0;
}