#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});  // Start with the start_node with a probability of 1.0
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
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int n = 3, start_node = 0, end_node = 2;
    double result = sol.maxProbability(n, edges, succProb, start_node, end_node);
    cout << "Max Probability: " << result << endl;
    return 0;
}
