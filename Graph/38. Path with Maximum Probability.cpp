#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        pq.push({1.0, start_node});  // start with the start_node with a probability of 1.0
        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;

        while (!pq.empty()) {
            auto [currentProb, currentNode] = pq.top();
            pq.pop();

            if (currentNode == end_node) {
                return currentProb;
            }

            for (auto [neighbor, edgeProb] : graph[currentNode]) {
                double newProb = currentProb * edgeProb;
                if (newProb > probabilities[neighbor]) {
                    probabilities[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }
        return 0.0;
    }
};

int main() {
    return 0;
}
