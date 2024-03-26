#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();
            while (size--) {
                int currentCity = q.front().first;
                int currentCost = q.front().second;
                q.pop();
                if (graph.count(currentCity) == 0) continue;
                for (auto neighbor : graph[currentCity]) {
                    int nextCity = neighbor.first;
                    int flightCost = neighbor.second;
                    if (flightCost + currentCost >= dist[nextCity]) continue;
                    dist[nextCity] = flightCost + currentCost;
                    q.push({nextCity, dist[nextCity]});
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    return 0;
}